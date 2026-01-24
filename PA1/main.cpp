/**
 * @file main.cpp
 * @description Basic test driver for CPSC 221 PA1
 *              You can add your own testing code to this file,
 *              but this file will not be submitted for grading.
 * @author CPCS 221
**/


#include "chain.h"
#include <iostream>
#include "cs221util/PNG.h"
using namespace cs221util;
using namespace std;

int main() {
	/**
	 * Use your own images and other tests to test your code!
	 * Some tests you should write:
	 * 1) building and rendering blocks
	 * 2) copying a chain (may or may not have been modified with ToRowOrder/ToColumnOrder/Transpose)
	 * 3) assigning one chain to another
	 */
	PNG im;
	im.readFromFile("images-original/k-480x360.png");
	// construct a Chain object with 4 columns
	Chain c(im, 4);

	// render at 1x scale
	c.Render(1).writeToFile("images-output/k-render1x.png");

	// convert to column order
	c.ToColumnOrder();

	// render at 2x scale
	c.Render(2).writeToFile("images-output/k-col-render2x.png");
	
	return 0;
}
