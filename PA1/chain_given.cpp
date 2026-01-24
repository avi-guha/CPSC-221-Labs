/**
 * @file chain_given.cpp
 * @description Instructor implementation of partial Chain functions, CPSC 221 PA1
 * @author CPSC 221
**/

#include "chain.h"

/**
 * Given functions for the Chain class.
 *
 * ****WARNING****
 *
 * You should not modify this file.  It is not one of the files
 * you will submit.  We will grade your submission using the
 * original version of this file.
**/

/* no-argument constructor */
Chain::Chain() {
    roworder = true;
    rows_ = 0;
    columns_ = 0;
    NW = NULL;
}

/**
 * accessor for how many rows to use when rendering the chain.
**/
int Chain::NumRows() const {
    return rows_;
}

/**
 * accessor for how many columns to use when rendering the chain.
**/
int Chain::NumCols() const {
    return columns_;
}

/**
 * accessor for whether the linked list is stored in row-order
**/
bool Chain::IsRowOrder() const {
    return roworder;
}

/* copy constructor */
Chain::Chain(Chain const& other) {
    roworder = true;
    rows_ = 0;
    columns_ = 0;
    NW = nullptr;
    Copy(other);
}

/* assignment operator */
Chain & Chain::operator=(Chain const& rhs) {
    if (this != &rhs) {
        Clear(); // you'll implement clear
        Copy(rhs);
    }
    return *this;
}

/**
 * checks for empty list
 */
bool Chain::Empty() const {
    return NW == nullptr;
}
