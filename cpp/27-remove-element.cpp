/*
 Source : https://oj.leetcode.com/problems/remove-element/
 Author : Alex Xu
 Date   : Feb 05, 2015

 Given an array and a value, remove all instances of that value in place and return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 A[m] +-+-+-+-+   +-+-+-+
      | | | | |...| | | |
      +-+-+-+-+   +-+-+-+
       ^               ^
       |head           |tail

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int head = 0;
        int tail = n-1;

        while(head <= tail) {
            if (A[head] == elem) {
                A[head] = A[tail];
                -- tail;
                continue; // continue test A[tail] that has been move to A[head]
            }
            ++ head;
        }

        return tail+1;
    }
};


void printArray(int a[], int len)
{
    for (int i=0; i<len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;

    //int A[] = {3,3};
    //int A[] = {5};
    //int A[] = {1, 5};
    //int A[] = {5, 1}
    //int A[] = {5, 1, 7};
    int A[] = {1, 3, 7};
    //int A[] = {1, 5, 7};
    //int A[] = {1, 7, 5};
    int len = sizeof(A)/sizeof(A[0]);
    
        printArray(A, len);
    int newLen = s.removeElement(A, len, 5);
    printArray(A, newLen);

    return 0;
}
