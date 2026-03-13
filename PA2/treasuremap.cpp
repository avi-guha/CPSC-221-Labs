/**
 * @file treasuremap.cpp
 * @description Implementations for PA2, TreasureMap class
 * @author (vhzh)
 * @author (aguha01)
**/
#include "treasuremap-private.h"
#include "treasuremap.h"
#include "queue.h"
// #include <utility>

#define BLUEMASK 0b00000011
#define GREENMASK 0b00001100
#define REDMASK 0b00110000
using namespace std;

TreasureMap::TreasureMap(const PNG& baseim, const PNG& mazeim, pair<int, int> s) {
	base = baseim;
	maze = mazeim; 
	start = s; 
}

void TreasureMap::SetGrey(PNG& im, pair<int, int> loc) {
	RGBAPixel *pixel = im.getPixel(loc.first, loc.second);
	pixel -> r = 2 * (pixel -> r / 4); 
	pixel -> g = 2 * (pixel -> g / 4);
	pixel -> b = 2 * (pixel -> b / 4);
}

void TreasureMap::SetLOB(PNG& im, pair<int, int> loc, int d) {
	int bitd = d % 64;

    int rVal = (bitd & REDMASK) >> 4;
    int gVal = (bitd & GREENMASK) >> 2;
    int bVal = (bitd & BLUEMASK) >> 0;

    RGBAPixel *pixel = im.getPixel(loc.first, loc.second);

    pixel->r = (pixel->r & 0b11111100) | rVal;  
    pixel->g = (pixel->g & 0b11111100) | gVal;
    pixel->b = (pixel->b & 0b11111100) | bVal;
}

PNG TreasureMap::RenderMap() {
	
	// copy the first
	PNG baseCopy = base; 
	// is visited vector and distance vectors. 
	vector<vector<bool>> isVisited(base.width(), vector<bool>(base.height(), false));
	vector<vector<int>> distance(base.width(), vector<int>(base.height(), 0)); 
	
	// queue
	Queue <pair<int,int>> toSearch; 

	// step 3
    isVisited[start.first][start.second] = true;      // set start as visited
    distance[start.first][start.second] = 0;          // set distance to start to 0
    SetLOB(baseCopy, start, 0);
    toSearch.Enqueue(start);

    // step 4
    while (!toSearch.IsEmpty()) {
        pair<int,int> curr = toSearch.Dequeue();
        
        for (auto &neighbour : Neighbours(curr)) {
            if (Good(isVisited, curr, neighbour)) {
                isVisited[neighbour.first][neighbour.second] = true;
                distance[neighbour.first][neighbour.second] = distance[curr.first][curr.second] + 1;
                SetLOB(baseCopy, neighbour, distance[neighbour.first][neighbour.second]);
                toSearch.Enqueue(neighbour);
            }
        }
    }
        
	return baseCopy;
}


PNG TreasureMap::RenderMaze() {
	PNG baseCopy = base;

	vector<vector<bool>> isVisited(base.width(), vector<bool>(base.height(), false));
	Queue <pair<int,int>> toSearch; 

	isVisited[start.first][start.second] = true;
	toSearch.Enqueue(start);

	while (!toSearch.IsEmpty()) {
        pair<int,int> curr = toSearch.Dequeue();
		SetGrey(baseCopy, curr);
		
		for (auto &neighbour : Neighbours(curr)) {
            
			if (Good(isVisited, curr, neighbour)) {
                isVisited[neighbour.first][neighbour.second] = true;
				toSearch.Enqueue(neighbour);
			}
		}

	}

	for (int x = start.first - 3; x <= start.first + 3; x++) {
		for (int y = start.second - 3; y <= start.second + 3; y++) {
			if (x >= 0 && y >= 0 && x < (int) base.width() && y < (int) base.height()) {
				RGBAPixel * pixel = baseCopy.getPixel(x, y);
				pixel->r = 255;
				pixel->g = 0;
				pixel->b = 0;
			}
		}
	}

	return baseCopy; 
}
// visited list, current position, next = neighbor
bool TreasureMap::Good(vector<vector<bool>>& v, pair<int, int> curr, pair<int, int> next) {
	int height = (int) base.height();
	int width = (int) base.width();

	bool inBounds = next.first >= 0 && next.second >= 0 
				&& next.first < width 
				&& next.second < height;
	if (!inBounds) {
		return false;
	}

	bool visited = v[next.first][next.second];
	RGBAPixel * currentPixel = maze.getPixel(curr.first, curr.second);
	RGBAPixel * nextPixel =  maze.getPixel(next.first, next.second);
	bool sameColour = (*currentPixel == *nextPixel);
	
	return inBounds && !visited && sameColour; 
		
	
}

vector<pair<int, int>> TreasureMap::Neighbours(pair<int, int> curr) {
	int dx = 1; 
	int dy = 1; 
	vector<pair<int,int>> neighbours = { {curr.first - dx, curr.second }, 
										 {curr.first, curr.second + dy },
										 {curr.first + dx, curr.second },
										 {curr.first, curr.second - dy }};
	return neighbours; 
		
}
/***********************************************
* IF YOU DECLARED ANY ADDITIONAL PRIVATE       *
* FUNCTIONS IN treasuremap-private.h, COMPLETE *
* THEIR IMPLEMENTATIONS BELOW                  *
***********************************************/
