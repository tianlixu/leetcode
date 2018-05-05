#include <iostream>
using namespace std;

/* Problem:
 * How to find the median of a sorted array?
 * How to find the median of an unsorted array?
 * How to find the median of an unsorted array without sorting?
 *
 * How to find the median of two sorted array? - from LeetCode
 * How to find the median of given N sorted arrays?
 *
 * Note:
 *    The median is the "middle number" in a sorted list of numbers.
 *    If it's odd, then it is the middle value.
 *    If it's even, it's the average of the two middle values.
 */


// qsort in C++/Python/Java 
 

class Solution {
public:
    int getKth(int a[], int m, int b[], int n, int k) {
        int i = 0;
        int j = 0;
        int counter = 0;
        int kthValue;

        while (counter < k) {
            if (i<m && j<n) {
                if ( a[i] < b[j]) {
                    kthValue = a[i];
                    i++;
                }
                else {
                    kthValue = b[j];
                    j++;
                }
            }
            else if (i >= m) {
                kthValue = b[j];
                j++;
            }
            else { // j>=n
                kthValue = a[i];
                i++;
            }
        
            counter++;
        }

        return kthValue;
    }
};


int main()
{
    int a[] = {9, 18, 20, 21};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {1, 2, 3};
    int n = sizeof(b) / sizeof(b[0]);    

    Solution s;
    int k = 2;
    int kthValue = s.getKth(a, m, b, n, k);
    
    cout << k << ":" << kthValue <<endl;
}
