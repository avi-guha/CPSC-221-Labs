/**
 * @file deque.cpp
 * @description Implementations for PA2, Deque class
 * @author (vhzh)
 * @author (aguha01)
**/

#include "deque.h"

template <class T>
Deque<T>::Deque() {
    /* YOUR CODE HERE! */
    head = 0;
    size = 0;
}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
**/
template <class T>
void Deque<T>::PushR(T newItem) {
    /* YOUR CODE HERE! */
    data.push_back(newItem);
    size++; // increase data size
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The item that used to be at the left of the Deque.
**/
template <class T>
T Deque<T>::PopL() {
    /* YOUR CODE HERE! */
    T removed = data[head];
    head++; // new start of data vector
    size--; // decrease count if data size
    if (IsEmpty()) {
        head = 0; // reset start
        data.clear();
    }
    else if (head >= data.size() / 2) {
        data = vector<T>(data.begin() + head, data.begin() + head + size);
        head = 0; 
    }
    return removed; 
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Deque.
**/
template <class T>
T Deque<T>::PopR() {
    /* YOUR CODE HERE! */
    T removed = data[head + size - 1];
    size--;
    data.pop_back();
    if (IsEmpty()) {
        head = 0;
        data.clear();
    }
    return removed;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike PopL(), this operation does not alter the deque.
 *
 * @return The item at the front of the deque.
**/
template <class T>
T Deque<T>::PeekL() {
    /* YOUR CODE HERE! */
    T peeked = data[head];

    return peeked;
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike PopR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
**/
template <class T>
T Deque<T>::PeekR() {
    /* YOUR CODE HERE! */
    T peeked = data[head + size - 1];

    return peeked;
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
**/
template <class T>
bool Deque<T>::IsEmpty() const {
    return size == 0;

}
