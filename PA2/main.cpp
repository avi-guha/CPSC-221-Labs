/**
 * @file main.cpp
 * @author CPSC 221
 * @description Partial test of PA2 functionality
**/

#include "treasuremap.h"
#include "decoder.h"
#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

using namespace cs221util;
using namespace std;

int main()
{

	PNG maze;
	maze.readFromFile("images-original/zdesmaze.png");
	pair<int,int> start(69,359);

    PNG base;
    base.readFromFile("images-original/zdesbase.png");

    TreasureMap M(base, maze, start);

    PNG treasure = M.RenderMap();
	treasure.writeToFile("images-output/zdesembedded.png");
    PNG treasuremaze = M.RenderMaze();
	treasuremaze.writeToFile("images-output/zdesgreyedmaze.png");

    Decoder dec(treasure,start);
    PNG soln = dec.RenderSolution();
    PNG solnmaze = dec.RenderMaze();

    soln.writeToFile("images-output/zdessoln.png");
    solnmaze.writeToFile("images-output/zdessolnmaze.png");

    return 0;
}
