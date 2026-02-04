/**
 * @file block.cpp
 * @description Student implementation of Block functions, CPSC 221 PA1
 * @author (your CWLs here)
**/

#include "block.h"
#include <cmath>
#include <iostream>

/**
 * Return the dimension(width or height) of the block.
**/
int Block::Dimension() const {
	/* your code here */
	return 0;
}

/**
 * Renders the given block onto img with its upper
 * left corner at (x, y). Assumes the rendered block fits on the
 * image.
 * The block is enlarged using nearest-neighbour scaling
 * (i.e. no pixel blending).
 * @pre scale >= 1
**/
void Block::Render(PNG& img, int x, int y, int scale) const {
	/* your code here */

}

/**
 * Creates a block that is dimension X dimension pixels in size
 * by copying the pixels from (x, y) to (x+dimension-1, y+dimension-1)
 * in img. Assumes img is large enough to supply these pixels.
**/
void Block::Build(PNG& img, int x, int y, int dimension) {
	/* your code here */

}

/**
 * Rearranges the image data in this Block so that it is transposed
 * (flipped) over the diagonal line from upper-left to lower-right
 * e.g.  1 2 3      1 4 7
 *       4 5 6  ->  2 5 8
 *       7 8 9      3 6 9
**/
void Block::Transpose() {
	/* your code here */

}
