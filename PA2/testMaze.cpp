/**
 * @file testMaze.cpp
 * @author CPSC 221
 * @description Basic test cases for PA2 maze/decoder functionality
**/

#include <iostream>
#include <limits.h>
#include <sys/stat.h>
#include <vector>

#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

#include "decoder.h"
#include "treasuremap.h"

using namespace std;
using namespace cs221util;

#define IMAGEDIR "images-original/"
#define SOLNIMGDIR "images-solution/"

/**
 * Test Cases
 * these are just examples of a logical flow similar to 
 * that of main.cpp. We suggest decoupling the embedding
 * tests from the decoding tests, but we leave it to you
 * to do so.
**/

/********************************************************
* Test function declarations                            *
* ----------------------------------------------------- *
* These are just examples of a logical flow similar to  *
* that of main.cpp. We suggest decoupling the embedding *
* tests from the decoding tests, but we leave it to you *
* to do so.                                             *
********************************************************/

void TestTreasureMapBasicNoCycles();
void TestDecoderBasicCycles();

/**********************
* Program entry point *
**********************/

int main(int argc, char* argv[]) {
    // Call test functions
    TestTreasureMapBasicNoCycles();
    TestDecoderBasicCycles();
    return 0;
}

/*******************************
* Test function implementation *
*******************************/

void TestTreasureMapBasicNoCycles() {
    cout << "TreasureMap::basic no cycles" << endl;

    PNG maze;
    maze.readFromFile("images-original/snake.png");
    pair<int, int> start(1, 1);

    PNG base;
    base.readFromFile("images-original/sunshine.png");

    TreasureMap M(base, maze, start);

    PNG treasure = M.RenderMap();
    //treasure.writeToFile("images-output/embeddedsnake.png");
    PNG treasureans;
    treasureans.readFromFile("images-solution/embeddedsnake.png");
    bool treasurematch = (treasure == treasureans);

    PNG treasuremaze = M.RenderMaze();
    //treasuremaze.writeToFile("images-output/greyedsnake.png");
    PNG treasuremazeans;
    treasuremazeans.readFromFile("images-solution/greyedsnake.png");
    bool treasuremazematch = (treasuremaze == treasuremazeans);

    Decoder dec(treasure, start);

    PNG soln = dec.RenderSolution();
    //soln.writeToFile("images-output/solnsnake.png");
    PNG solnans;
    solnans.readFromFile("images-solution/solnsnake.png");
    bool solnmatch = (soln == solnans);

    PNG solnmaze = dec.RenderMaze();
    //solnmaze.writeToFile("images-output/solnsnakemaze.png");
    PNG solnmazeans;
    solnmazeans.readFromFile("images-solution/solnsnakemaze.png");
    bool solnmazematch = (solnmaze == solnmazeans);

    if (treasurematch && treasuremazematch && solnmatch && solnmazematch) {
        cout << "Test case passed." << endl;
    }
    else {
        cout << "Test case failed." << endl;
    }
}

void TestDecoderBasicCycles() {
    cout << "Decoder::basic cycles" << endl;

    PNG maze;
    maze.readFromFile("images-original/maze.png");
    pair<int, int> start(1, 1);

    PNG base;
    base.readFromFile("images-original/sunshine.png");

    TreasureMap M(base, maze, start);

    PNG treasure = M.RenderMap();
    //treasure.writeToFile("images-output/embeddedmaze.png");
    PNG treasureans;
    treasureans.readFromFile("images-solution/embeddedmaze.png");
    bool treasurematch = (treasure == treasureans);

    PNG treasuremaze = M.RenderMaze();
    //treasuremaze.writeToFile("images-output/greyedmaze.png");
    PNG treasuremazeans;
    treasuremazeans.readFromFile("images-solution/greyedmaze.png");
    bool treasuremazematch = (treasuremaze == treasuremazeans);

    Decoder dec(treasure, start);

    PNG soln = dec.RenderSolution();
    //soln.writeToFile("images-output/solnmaze.png");
    PNG solnans;
    solnans.readFromFile("images-solution/solnmaze.png");
    bool solnmatch = (soln == solnans);

    PNG solnmaze = dec.RenderMaze();
    //solnmaze.writeToFile("images-output/solnmazemaze.png");
    PNG solnmazeans;
    solnmazeans.readFromFile("images-solution/solnmazemaze.png");
    bool solnmazematch = (solnmaze == solnmazeans);

    if (treasurematch && treasuremazematch && solnmatch && solnmazematch) {
        cout << "Test case passed." << endl;
    }
    else {
        cout << "Test case failed." << endl;
    }
}