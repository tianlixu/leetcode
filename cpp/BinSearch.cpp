#include <iostream>
using namespace std;

/*
 * Problem:
 *
 * Solution:
 *     Divide and conquer strategy
 */
class Solution {
public:
    /*
     * binary search in a sorted array [1, 2, 3, 5, 7, 8]
     */
    int binSearch(int a[], int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        
        int mid = (low + high) / 2;
        if (target == a[mid]) {
            return mid;
        }
        else if (target < a[mid]) {
            return binSearch(a, low, mid-1, target);
        }
        else {
            return binSearch(a, mid+1, high, target);
        }
    }

    
    /*
     * Search left or right?
     *
     * 1. Find the half one that is in sequence.
     * 2. Whether the target falls in this one.
     * 3. If yes, then search this one; otherwise search the other.
     */
    int binSearch2(int a[], int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        
        int mid = (low + high) / 2;
        if (target == a[mid]) {
            return mid;
        } else if (a[low] < a[mid]) {
            if (a[low] <= target && target < a[mid]) {
                return binSearch2(a, low, mid-1, target);
            } else {
                return binSearch2(a, mid+1, high, target);
            }
        } else {
            if (a[mid] < target && target <= a[high]) {
                return binSearch2(a, mid+1, high, target);
            } else {
                return binSearch2(a, low, mid-1, target);
            }
        }
    }
};


int main()
{
    int a[] = {7, 8, 1, 2, 3, 5, 6};
    //int a[] = {1, 2, 3, 5};
    int len = sizeof(a)/sizeof(a[0]);

    Solution s;
    int index = s.binSearch2(a, 0, len-1, 6);

    cout << "index=" << index << endl;
}
