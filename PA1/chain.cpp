/**
 * @file chain.cpp
 * @description Student implementation of Chain functions, CPSC 221 PA1
 * @author 60702594
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
    NW = NULL;
    roworder = true;
    columns_ = numCols;

    int blockDim = imIn.width() / numCols;
    rows_ = imIn.height() / blockDim;

    Node* curr = NULL;

    // Build chain in row order
    for (int row = 0; row < rows_; row++) {
        for (int col = 0; col < columns_; col++) {
            Block b;
            b.Build(imIn, col * blockDim, row * blockDim, blockDim);
            curr = InsertAfter(curr, b);
        }
    }
}

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
**/
Chain::~Chain() {
	/* your code here */
    Clear();
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
    Node* newNode = new Node(ndata);

    if (p == NULL) {
        // Insert as head
        newNode->next = NW;
        NW = newNode;
    } else {
        // Insert after p
        newNode->next = p->next;
        p->next = newNode;
    }

    return newNode;
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
**/
void Chain::Clear() {
	/* your code here */
    Node* curr = NW;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    NW = NULL;
    rows_ = 0;
    columns_ = 0;
    roworder = true;
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
    rows_ = other.rows_;
    columns_ = other.columns_;
    roworder = other.roworder;
    NW = NULL;

    Node* otherCurr = other.NW;
    Node* curr = NULL;

    while (otherCurr != NULL) {
        curr = InsertAfter(curr, otherCurr->data);
        otherCurr = otherCurr->next;
    }
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
    if (NW == NULL) {
        return PNG();
    }

    int blockDim = NW->data.Dimension();
    int imgWidth = columns_ * blockDim * scale;
    int imgHeight = rows_ * blockDim * scale;

    PNG img(imgWidth, imgHeight);

    Node* curr = NW;
    int index = 0;

    while (curr != NULL) {
        int row, col;

        if (roworder) {
            row = index / columns_;
            col = index % columns_;
        } else {
            col = index / rows_;
            row = index % rows_;
        }

        int x = col * blockDim * scale;
        int y = row * blockDim * scale;

        curr->data.Render(img, x, y, scale);

        curr = curr->next;
        index++;
    }

    return img;
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
    if (roworder) {
        return; // Already in row order
    }

    int total = Length();
    if (total == 0) {
        return;
    }

    // Create array of node pointers to hold all nodes
    vector<Node*> nodes(total);
    Node* curr = NW;
    for (int i = 0; i < total; i++) {
        nodes[i] = curr;
        curr = curr->next;
    }

    // Reorder: currently in column order (col-major), convert to row order (row-major)
    // Current column order: index = col * rows_ + row
    // Target row order: index = row * columns_ + col

    // Build new order
    vector<Node*> newOrder(total);
    for (int row = 0; row < rows_; row++) {
        for (int col = 0; col < columns_; col++) {
            int oldIndex = col * rows_ + row;  // column order index
            int newIndex = row * columns_ + col;  // row order index
            newOrder[newIndex] = nodes[oldIndex];
        }
    }

    // Relink nodes
    NW = newOrder[0];
    for (int i = 0; i < total - 1; i++) {
        newOrder[i]->next = newOrder[i + 1];
    }
    newOrder[total - 1]->next = NULL;

    roworder = true;
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
    if (!roworder) {
        return; // Already in column order
    }

    int total = Length();
    if (total == 0) {
        return;
    }

    // array of node pointers holds all nodes
    vector<Node*> nodes(total);
    Node* curr = NW;
    for (int i = 0; i < total; i++) {
        nodes[i] = curr;
        curr = curr->next;
    }

    // Reorder: currently in row order (row-major), convert to column order (col-major)

    vector<Node*> newOrder(total);
    for (int col = 0; col < columns_; col++) {
        for (int row = 0; row < rows_; row++) {
            int oldIndex = row * columns_ + col;  
            int newIndex = col * rows_ + row;  
            newOrder[newIndex] = nodes[oldIndex];
        }
    }

    // Relink nodes
    NW = newOrder[0];
    for (int i = 0; i < total - 1; i++) {
        newOrder[i]->next = newOrder[i + 1];
    }
    newOrder[total - 1]->next = NULL;

    roworder = false;
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
    
    if (NW == NULL) {
        return;
    }

    
    Node* curr = NW;
    while (curr != NULL) {
        curr->data.Transpose();
        curr = curr->next;
    }

    // Swap rows and columns
    int temp = rows_;
    rows_ = columns_;
    columns_ = temp;

    // Reorder the chain to match the transposed layout

    int total = Length();
    if (total == 0) {
        return;
    }

    // array of node pointers holds all nodes
    vector<Node*> nodes(total);
    curr = NW;
    for (int i = 0; i < total; i++) {
        nodes[i] = curr;
        curr = curr->next;
    }

    // Build new order for transpose

    vector<Node*> newOrder(total);

    if (roworder) {
        // Was in row order, rearrange for transposed row order
        int oldRows = columns_;  
        int oldCols = rows_;     

        for (int i = 0; i < total; i++) {
            int oldRow = i / oldCols;
            int oldCol = i % oldCols;
            int newIndex = oldCol * columns_ + oldRow;
            newOrder[newIndex] = nodes[i];
        }
    } else {

        int oldRows = columns_;  
        int oldCols = rows_;     

        for (int i = 0; i < total; i++) {

            int oldCol = i / oldRows;
            int oldRow = i % oldRows;

            int newIndex = oldRow * rows_ + oldCol;
            newOrder[newIndex] = nodes[i];
        }
    }

    // Relink nodes
    NW = newOrder[0];
    for (int i = 0; i < total - 1; i++) {
        newOrder[i]->next = newOrder[i + 1];
    }
    newOrder[total - 1]->next = NULL;
}

/**************************************************
* IF YOU HAVE DECLARED PRIVATE FUNCTIONS IN       *
* chain-private.h, COMPLETE THEIR IMPLEMENTATIONS *
* HERE                                            *
**************************************************/

/**
 * Returns the total number of nodes in the chain.
 * @return number of nodes in the chain
**/
int Chain::Length() const {
    int count = 0;
    Node* curr = NW;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * Returns a pointer to the node at the given index (0-based).
 * @param index - the position in the chain (0-based)
 * @return pointer to the node at index, or NULL if out of bounds
**/
Node* Chain::GetNodeAt(int index) const {
    if (index < 0) {
        return NULL;
    }
    Node* curr = NW;
    int i = 0;
    while (curr != NULL && i < index) {
        curr = curr->next;
        i++;
    }
    return curr;
}

