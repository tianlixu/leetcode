/*
 Source : https://oj.leetcode.com/problems/merge-sorted-array/
 Author : Alex Xu
 Date   : Feb 04, 2015

 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space (size that is greater or equal to m + n)
 to hold additional elements from B. The number of elements initialized in A and
 B are m and n respectively.

 A[m] +-+-+-+-+-+-+-+-+
      | | | | | | | | | .....
      +-+-+-+-+-+-+-+-+
         ^     ^       ^
         |pos  |j      |m+i

 B[n] +-+-+-+-+-+
      | | | | | |
      +-+-+-+-+-+
         ^
         |i
*/

#include <iostream>
using namespace std;

class Solution {
private:
    void insertAt(int A[], int last, int at, int value) {
        // shifting
        for (int i=last; i>=at; --i) {
            A[i+1] = A[i];
        }

        A[at] = value;
    }

public:
    void merge(int A[], int m, int B[], int n) {
        int pos = 0;
        for (int i=0; i<n; i++) {
            int j = pos;
            while (j<m+i) {
                if (B[i] < A[j]) {
                    insertAt(A, m+i-1, j, B[i]);
                    break;
                }
                ++j;
            }

            if (j == m+i) // to the end of A[]
                A[j] = B[i];

            pos = j+1;
        }
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

    /*
    int A[9] = {1};
    int B[1] = {2};
    s.merge(A, 1, B, 1);

    int A[9] = {2};
    int B[1] = {1};
    s.merge(A, 1, B, 1);

    int A[9] = {};
    int B[1] = {1};
    s.merge(A, 0, B, 1);

    int A[9] = {1};
    int B[] = {};
    s.merge(A, 1, B, 0);

    int A[9] = {1, 3, 5, 7};
    int B[4] = {2, 4, 6, 8};
    s.merge(A, 4, B, 4);

    int A[9] = {2, 4, 6, 8};
    int B[4] = {1, 3, 5, 7};
    s.merge(A, 4, B, 4);
    */
    int A[9] = {1, 3, 6, 7};
    int B[4] = {2, 4, 5, 8};
    s.merge(A, 4, B, 4);
    /*
    int A[9] = {1, 2, 3};
    int B[4] = {2, 5, 6};
    s.merge(A, 3, B, 3);
    */

    printArray(A, 9);

    return 0;
}
