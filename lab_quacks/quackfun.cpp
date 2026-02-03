/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

    /**
     * Sums items in a stack.
     * @param s A stack holding values to sum.
     * @return The sum of all the elements in the stack, leaving the original
     *  stack in the same state (unchanged).
     *
     * @note You may modify the stack as long as you restore it to its original
     *  values.
     * @note You may use only two local variables of type T in your function.
     *  Note that this function is templatized on the stack's type, so stacks of
     *  objects overloading the + operator can be summed.
     * @note We are using the Standard Template Library (STL) stack in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint Think recursively!
     */
    template <typename T>
    T sum(stack<T>& s)
    {
        if (s.empty()) {
            return T();
        }
        T temp = s.top();
        s.pop();
        T result = temp + sum(s);
        s.push(temp);
        return result;
    }

    /**
     * Reverses even sized blocks of items in the queue. Blocks start at size
     * one and increase for each subsequent block.
     * @param q A queue of items to be scrambled
     *
     * @note Any "leftover" numbers should be handled as if their block was
     *  complete.
     * @note We are using the Standard Template Library (STL) queue in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint You'll want to make a local stack variable.
     */
    template <typename T>
    void scramble(queue<T>& q)
    {
        stack<T> s;
        queue<T> q2;
        int block_size = 1;
        
        while (!q.empty()) {
            // Process blocks of increasing size
            for (int i = 0; i < block_size && !q.empty(); i++) {
                if (block_size % 2 == 0) {
                    // Even block size: reverse using stack
                    s.push(q.front());
                } else {
                    // Odd block size: keep in order
                    q2.push(q.front());
                }
                q.pop();
            }
            
            // Pop from stack (reverses even blocks) and push to q2
            while (!s.empty()) {
                q2.push(s.top());
                s.pop();
            }
            
            block_size++;
        }
        
        // Copy q2 back to q
        while (!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
    }

    /**
     * @return true if the parameter stack and queue contain only elements of
     *  exactly the same values in exactly the same order; false, otherwise.
     *
     * @note You may assume the stack and queue contain the same number of items!
     * @note There are restrictions for writing this function.
     * - Your function may not use any loops
     * - In your function you may only declare ONE local boolean variable to use in
     *   your return statement, and you may only declare TWO local variables of
     *   parametrized type T to use however you wish.
     * - No other local variables can be used.
     * - After execution of verifySame, the stack and queue must be unchanged. Be
     *   sure to comment your code VERY well.
     */
    template <typename T>
    bool verifySame(stack<T>& s, queue<T>& q)
    {
        bool retval = true;
        T temp1; // for stack element
        T temp2; // for queue element
        
        // Base case: stack is empty means we've compared all elements
        if (s.empty()) {
            return true;
        }
        
        // Pop from stack to recurse to the bottom first
        temp1 = s.top();
        s.pop();
        
        // Recurse: go to bottom of stack first, then compare on the way back up
        // This way bottom of stack compares with front of queue
        retval = verifySame(s, q);
        
        // Now compare: after recursion, q.front() is the element that should
        // match this level's stack element (bottom of stack matches front of queue)
        temp2 = q.front();
        q.pop();
        
        // Check if current elements match and all previous comparisons passed
        retval = retval && (temp1 == temp2);
        
        // Restore: push stack element back, push queue element to back
        // This restores both to their original state
        s.push(temp1);
        q.push(temp2);
        
        return retval;
    }
}
