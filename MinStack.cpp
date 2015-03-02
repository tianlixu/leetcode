/*
 Source : https://oj.leetcode.com/problems/min-stack/
 Author : Alex Xu
 Date   : Mar 02, 2015
 Problem:
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Solution: 
C++ container std::stack supports push, pop, top with O(1), what we need to consider is only getMin().
Using two stacks, one for the original data, the other for the minimal data.
 */

#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        /* push into minStk if necessary. 
         * Note that the value in minStk is not unique, for example, push 0, 1, 0
         * the minStk contains 0, 0
         */
        if (minStk.empty() || x <= minStk.top())
            minStk.push(x);
        
        // always push into stk
        stk.push(x);
    }

    void pop() {
        // pop from minStk if necessary
        if (minStk.top() == stk.top())
            minStk.pop();
            
        // always pop from stk
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
    
private:
    stack<int> stk;
    stack<int> minStk;
};
