/**
 * @file queue.h
 * @author CPSC 221
 * @description Declarations for PA2, Queue class
 *              THIS FILE WILL NOT BE SUBMITTED
**/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "deque.h"

/**
 * Queue class: represents a standard queue. Templated to hold elements of
 * any type. **You must only use the private member deque as your
 * storage space! You cannot create new private member variables to hold
 * your objects!** It is up to you to determine how to use it.
 *
 * Your Queue class should have O(1) running time over n operations
 * (amortized). 
 *
 * You **should not** modify this file for the PA!
 *
**/
template <class T>
class Queue 
{
  public:
    /**
     * Adds the parameter object to the back of the Queue.
     *
     * @note This fuction should have O(1) behavior over n operations!
     *
     * @param newItem object to be added to the Queue.
    **/
    void Enqueue(T newItem);

    /**
     * Removes the object at the front of the Queue, and returns it to
     * the caller. You may assume that this function is only called
     * when the Queue is non-empty.
     *
     * @note This function should have O(1) behavior over n operations!
     *
     * @return The item that used to be at the front of the Queue.
    **/
    T Dequeue();


    /**
     * Finds the object at the front of the Queue, and returns it to
     * the caller. Unlike Dequeue(), this operation does not alter the
     * queue. You may assume that this function is only called when the
     * Queue is non-empty.
     *
     * @note This function should have O(1) behavior over n operations!
     *
     * @return The item at the front of the queue.
    **/
    T Peek();

    /**
     * Determines if the Queue is empty.
     *
     * @note This function should have O(1) behavior over n operations!
     *
     * @return bool which is true if the Queue is empty, false
     *	otherwise.
    **/
    bool IsEmpty() const;

  private:
    Deque<T> myQueue;
};

#include "queue.cpp"
#endif
