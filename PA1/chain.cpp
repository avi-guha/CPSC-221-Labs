/**
 * @file chain.cpp
 * @description Student implementation of Chain functions, CPSC 221 PA1
 * @author (your CWLs here)
**/

#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions
// Complete all of the missing implementation
// and submit this file for grading.

/* Most useful constructor. Most easily implemented using your
 * implementation of Block.Build and Chain.InsertAfter.
 * Builds a chain out of the blocks in the
 * given image in rows. The blocks we create
 * have width equal to imIn.width()/numCols
 * and height equal to imIn.height() / block width.
 *
 * @param imIn     The image providing the blocks
 * @param numCols  The number of block columns into which the image will be divided
 * @pre   imIn's width is exactly divisible by numCols
 * @pre   imIn's height will be exactly divisible by the resulting block dimension
**/
Chain::Chain(PNG& imIn, int numCols) {
    /* your code here */

}

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
**/
Chain::~Chain() {
	/* your code here */
    
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
**/
Node* Chain::InsertAfter(Node* p, const Block &ndata) {
	/* your code here */
	return nullptr;
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
**/
void Chain::Clear() {
	/* your code here */

}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
**/
void Chain::Copy(Chain const &other) {
	/* your code here */

}

/**
 * Takes the current chain and renders it into a
 * correctly sized PNG. The blocks in the chain
 * are placed in the image according to their row/column positions in the chain.
 * The output image will be enlarged using nearest-neighbour scaling
 * (i.e. no pixel blending).
 * @pre scale >= 1
**/
PNG Chain::Render(int scale) {
    /* your code here */
    return PNG();
}

/**
 * Rearranges the links in the list so that each node's
 * next pointer moves horizontally across an image, respecting
 * the image's number of columns and rows.
 * 
 * Has no effect on a list which is already in row order.
**/
void Chain::ToRowOrder() {
    /* your code here */

}

/**
 * Rearranges the links in the list so that each node's
 * next pointer moves vertically across an image, respecting
 * the image's number of columns and rows.
 *
 * Has no effect on a list which is already in column order.
**/
void Chain::ToColumnOrder() {
    /* your code here */

}

/**
 * Rearranges the links in the list and each node's Block data
 * so that the rendered image appears transposed over the NW-SE diagonal.
 * 
 * e.g.
 * 
 *  A -> B                     A     C  (individual blocks must also be transposed)
 *      /    --Transpose-->    |   / |
 *    /                        v /   v
 *  C -> D                     B     D
**/
void Chain::Transpose() {
    /* your code here */

}

/**************************************************
* IF YOU HAVE DECLARED PRIVATE FUNCTIONS IN       *
* chain-private.h, COMPLETE THEIR IMPLEMENTATIONS *
* HERE                                            *
**************************************************/

