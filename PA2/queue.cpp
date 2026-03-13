/**
 * @file queue.cpp
 * @description Implementations for PA2, Queue class
 * @author (vhzh)
**/

#include "queue.h"

/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
**/
template <class T>
void Queue<T>::Enqueue(T newItem) {
    myQueue.PushR(newItem);
}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The item that used to be at the front of the Queue.
**/
template <class T>
T Queue<T>::Dequeue() {
    /* YOUR CODE HERE! */
    T removed = myQueue.PopL();

    return removed;
}

/**
 * Finds the object at the front of the Queue, and returns it to the
 * caller. Unlike Dequeue(), this operation does not alter the queue.
 *
 * @return The item at the front of the queue.
**/
template <class T>
T Queue<T>::Peek() {
    /* YOUR CODE HERE! */
    T peeked = myQueue.PeekL();

    return peeked;
}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
**/
template <class T>
bool Queue<T>::IsEmpty() const {
    return myQueue.IsEmpty();
}
