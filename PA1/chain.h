/**
 * @file chain.h
 * @description Declaration of Chain class and functions, CPSC 221 PA1
 * @author CPSC 221
**/

#ifndef _CHAIN_H_
#define _CHAIN_H_

#include <string>
#include <iostream>
#include "block.h"
using namespace std;


/**
 * The Node class should normally be private to the List class following the principle of
 * encapsulation---the end user does not need to know our node-based
 * implementation details.
 * 
 * However, for the purpose of testing this PA, we will make this a public class.
**/
class Node {
    public:
        // default constructor
        Node() : next(NULL), data(Block()) {};
        // data provided constructor
        Node(const Block& ndata) : next(NULL), data(ndata) {};

        Node* next; // pointer to next node in chain
        Block data; // data held by Node
};

/**
 * Chain: This is a container class for blocks. It is implemented
 * as a singly-linked list of nodes, each of which contains a block.
 *
 * You should not remove anything from this class definition, but
 * you may find it helpful to add your own private helper functions to it.
**/

class Chain {
    public:
        Chain();
        Chain(PNG &imIn, int numCols);
        Chain(const Chain &other);

        Chain &operator=(const Chain &rhs);

        int NumRows() const;
        int NumCols() const;
        bool IsRowOrder() const;
        bool Empty() const;

        /* =============== end of given functions ====================*/

        /* =============== public PA1 FUNCTIONS =========================*/

        ~Chain();
   
        PNG Render(int scale);

        void ToRowOrder();
        void ToColumnOrder();

        void Transpose();

        /* =============== end of public PA1 FUNCTIONS =========================*/

    private:
        /*
         * Private member variables.
         *
         * You must use these as specified in the documentation and may not rename them.
         * You may add more into chain-private.h if you need them.
        **/

        Node* NW; // pointer to first node in chain or NULL if chain is empty

        int rows_; // number of rows of blocks in chain. Use this when rendering
        int columns_; // number of columns of blocks in chain. Use this when rendering

        bool roworder; // whether the links in the chain are aligned to rows or to columns

        /**
         * Private helper functions.
        **/

        /* =================== private PA1 functions ============== */

        /**
         * Destroys all dynamically allocated memory associated with the
         * current Chain class. Clear() is called
         * by destructor and operator=.
        **/
        void Clear();

        /**
         * Copies the parameter other Chain into the current Chain.
         * Does not free any memory. Called by copy constructor and op=.
         * @param other = The Chain to be copied.
        **/
        void Copy(const Chain &other);


        Node* InsertAfter(Node* p, const Block &ndata);

        /**
         * If you wish to define any private functions or attributes
         * for the Chain class, write your definitions into "chain-private.h"
         */
        #include "chain-private.h"

        /* =================== end of private PA1 functions ============== */
};

#endif
