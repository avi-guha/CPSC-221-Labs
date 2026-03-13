/**
 * @file testStackQueue.cpp
 * @author CPSC 221
 * @description Basic test cases for PA2 stack/queue functionality
**/

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

/*****************************
* Test function declarations *
*****************************/

void TestStackBasicFunctions();
void TestQueueBasicFunctions();

/**********************
* Program entry point *
**********************/

int main(int argc, char* argv[]) {
    // Call test functions
    TestStackBasicFunctions();
    TestQueueBasicFunctions();
    return 0;
}

/*******************************
* Test function implementation *
*******************************/

void TestStackBasicFunctions() {
    cout << "Stack::basic functions" << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.Push(i);
    }
    while (!intStack.IsEmpty()) {
        result.push_back(intStack.Pop());
    }
    if (result == expected) {
        cout << "Test case passed." << endl;
    }
    else {
        cout << "Test case failed." << endl;
    }
}

void TestQueueBasicFunctions() {
    cout << "Queue::basic functions" << endl;
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.Enqueue(i);
    }
    while (!intQueue.IsEmpty()) {
        result.push_back(intQueue.Dequeue());
    }
    if (result == expected) {
        cout << "Test case passed." << endl;
    }
    else {
        cout << "Test case failed." << endl;
    }
}