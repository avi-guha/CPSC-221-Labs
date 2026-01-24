/**
 * @file block.h
 * @description Declaration of Block class and functions, CPSC 221 PA1
 * @author CPSC 221
**/

#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/RGBAPixel.h"
using namespace std;
using namespace cs221util;

class Block {

	public:
		/** 
		 * Creates a block that is dimension X dimension pixels in size
		 * by copying the pixels from (x, y) to (x+dimension-1, y+dimension-1)
		 * in img. Assumes img is large enough to supply these pixels.
		**/
		void Build(PNG &img, int x, int y, int dimension);

		/**
		 * Renders the given block onto img with its upper
		 * left corner at (x, y). Assumes the rendered block fits on the 
		 * image.
		 * The block is enlarged using nearest-neighbour scaling
		 * (i.e. no pixel blending).
		 * @pre scale >= 1
		**/
		void Render(PNG &img, int x, int y, int scale) const;

		/**
		 * Return the dimension(width or height) of the block.
		**/
		int Dimension() const;

		/**
		 * Rearranges the image data in this Block so that it is transposed
		 * (flipped) over the diagonal line from upper-left to lower-right
		 * e.g.  1 2 3      1 4 7
		 *       4 5 6  ->  2 5 8
		 *       7 8 9      3 6 9
		**/
		void Transpose();
   
	private:
		vector<vector<RGBAPixel>> data;
};

#endif
