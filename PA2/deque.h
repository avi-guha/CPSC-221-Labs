/**
 * @file deque.h
 * @author CPSC 221
 * @description Declarations for PA2, Deque class
 *              THIS FILE WILL NOT BE SUBMITTED
**/

#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <vector>

using namespace std;

/**
 * Deque class: represents a standard deque, templated to hold elements of
 * any type. **You must only use the private member vector as your
 * storage space! You cannot create new private member variables to hold
 * your objects!**  We have given you two other integers that you might
 * find useful.
 *
 * You **should not** modify this file for the PA! (We will use this 
 * version of the file for the test cases.)
 *
**/
template <class T>
class Deque
{
	public:

		/* Constructor, initializes member variables appropriately. */
		Deque();

		/**
		 * Adds the parameter object to the "right" end of the Deque.
		 *
		 * @note This fuction should have O(1) behavior over n operations!
		 * You may trust that the vector class resizes the array appropriately
		 * for additions to the structure, so no resizing is necessary for 
		 * function PushR.
		 *
		 * @param newItem object to be added to the Deque.
		**/
		void PushR(T newItem);

		/**
		 * Removes the object at the left of the Deque, and returns it to
		 * the caller. You may assume that this function is only called
		 * when the Deque is non-empty.
		 *
		 * To achieve amortized O(1) cost per operation, we will resize 
		 * the array downward at strategic points of the computation. 
		 * Specifically, suppose L is the index of the
		 * leftmost data element in the deque.
		 * If at any point the data will fit into array indices O..L-1,
		 * the array should be reinitialized to hold the data beginning
		 * at index 0 and occupying the next num cells, where num is the
		 * number of data elements in the structure. 
		 *
		 * @return The item that used to be at the left of the Deque.
		**/
		T PopL();

		/**
		 * Removes the object at the right of the Deque, and returns it to
		 * the caller. You may assume that this function is only called
		 * when the Deque is non-empty.
		 *
		 * To achieve amortized O(1) cost per operation, we will resize 
		 * the array downward at strategic points of the computation. 
		 * Specifically, suppose L is the index of the
		 * leftmost data element in the deque.
		 * If at any point the data will fit into array indices O..L-1,
		 * the array should be reinitialized to hold the data beginning
		 * at index 0 and occupying the next num cells, where num is the
		 * number of data elements in the structure. 
		 *
		 * @return The item that used to be at the right of the Deque.
		**/
		T PopR();

		/**
		 * Finds the object at the left of the Deque, and returns it to
		 * the caller. Unlike PopL(), this operation does not alter the
		 * deque. You may assume that this function is only called when the
		 * Deque is non-empty.
		 *
		 * @note This function should have O(1) behavior.
		 *
		 * @return The item at the left of the deque.
		**/
		T PeekL();

		/**
		 * Finds the object at the right of the Deque, and returns it to
		 * the caller. Unlike PopR(), this operation does not alter the
		 * deque. You may assume that this function is only called when the
		 * Deque is non-empty.
		 *
		 * @note This function should have O(1).
		 *
		 * @return The item at the right of the deque.
		**/
		T PeekR();

		/**
		 * Determines if the Deque is empty.
		 *
		 * @note This function should have O(1).
		 *
		 * @return bool which is true if the Deque is empty, false
		 *	otherwise.
		 **/
		bool IsEmpty() const;

	private:
		vector<T> data;  /* Store the deque data here! */
		int head;  
		int size;  
};

#include "deque.cpp"
#endif
