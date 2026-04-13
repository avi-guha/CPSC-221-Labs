/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

/**
 * Finds the minimum edge weight in the Graph graph.
 *
 * @param graph - the graph to search
 * @return the minimum edge weight
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    vector<Vertex> vertices = graph.getVertices();
    for (Vertex v : vertices)
        graph.setVertexLabel(v, "UNEXPLORED");

    vector<Edge> edges = graph.getEdges();
    for (const Edge& edge : edges)
        graph.setEdgeLabel(edge.source, edge.dest, "UNEXPLORED");

    Edge min = BFS(graph, graph.getStartingVertex());
    graph.setEdgeLabel(min.source, min.dest, "MIN");
    return min.weight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    unordered_map<Vertex, Vertex> parent;

    vector<Vertex> vertices = graph.getVertices();
    for (Vertex v : vertices)
        graph.setVertexLabel(v, "UNEXPLORED");

    vector<Edge> edges = graph.getEdges();
    for (const Edge& edge : edges)
        graph.setEdgeLabel(edge.source, edge.dest, "UNEXPLORED");

    queue<Vertex> q;
    graph.setVertexLabel(start, "VISITED");
    q.push(start);

    bool found = (start == end);
    while (!q.empty() && !found) {
        Vertex current = q.front();
        q.pop();

        vector<Vertex> adjacent = graph.getAdjacent(current);
        for (Vertex next : adjacent) {
            if (graph.getVertexLabel(next) != "UNEXPLORED")
                continue;

            parent[next] = current;
            graph.setVertexLabel(next, "VISITED");
            graph.setEdgeLabel(current, next, "DISCOVERY");

            if (next == end) {
                found = true;
                break;
            }

            q.push(next);
        }
    }

    int distance = 0;
    Vertex current = end;
    while (current != start) {
        Vertex previous = parent[current];
        graph.setEdgeLabel(previous, current, "MINPATH");
        current = previous;
        ++distance;
    }

    return distance;
}

/**
 * Finds a minimal spanning tree on a graph.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class given in dsets.cpp to help you with
 *  Kruskal's algorithm.
 *
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    vector<Edge> edges = graph.getEdges();
    for (const Edge& edge : edges)
        graph.setEdgeLabel(edge.source, edge.dest, "UNEXPLORED");

    vector<Vertex> vertices = graph.getVertices();
    unordered_map<Vertex, int> indexByVertex;
    indexByVertex.reserve(vertices.size());
    for (size_t i = 0; i < vertices.size(); ++i)
        indexByVertex[vertices[i]] = static_cast<int>(i);

    DisjointSets sets;
    sets.addelements(static_cast<int>(vertices.size()));

    sort(edges.begin(), edges.end());
    for (const Edge& edge : edges) {
        int sourceSet = sets.find(indexByVertex[edge.source]);
        int destSet = sets.find(indexByVertex[edge.dest]);
        if (sourceSet == destSet)
            continue;

        sets.setunion(sourceSet, destSet);
        graph.setEdgeLabel(edge.source, edge.dest, "MST");
    }
}

/**
 * Does a BFS of a graph, keeping track of the minimum
 *  weight edge seen so far.
 * @param g - the graph
 * @param start - the vertex to start the BFS from
 * @return the minimum weight edge
 */
Edge GraphTools::BFS(Graph& graph, Vertex start)
{
    queue<Vertex> q;
    graph.setVertexLabel(start, "VISITED");
    q.push(start);
    Edge min;
    min.weight = INT_MAX;

    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        vector<Vertex> adj = graph.getAdjacent(v);
        for (size_t i = 0; i < adj.size(); ++i) {
            if (graph.getVertexLabel(adj[i]) == "UNEXPLORED") {
                graph.setEdgeLabel(v, adj[i], "DISCOVERY");
                graph.setVertexLabel(adj[i], "VISITED");
                q.push(adj[i]);
                int weight = graph.getEdgeWeight(v, adj[i]);
                if (weight < min.weight) {
                    min.source = v;
                    min.dest = adj[i];
                    min.weight = weight;
                }
            } else if (graph.getEdgeLabel(v, adj[i]) == "UNEXPLORED") {
                graph.setEdgeLabel(v, adj[i], "CROSS");
                int weight = graph.getEdgeWeight(v, adj[i]);
                if (weight < min.weight) {
                    min.source = v;
                    min.dest = adj[i];
                    min.weight = weight;
                }
            }
        }
    }
    return min;
}
