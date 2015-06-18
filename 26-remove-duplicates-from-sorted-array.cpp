#include <iostream>
using namespace std;

/*
  Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  Author : Alex Xu
  Date   : June 18, 2015
  Problem:

  Remove Duplicates from Sorted Array
  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
  Do not allocate extra space for another array, you must do this in place with constant memory.
  For example, Given input array A = [1,1,2],
  Your function should return length = 2, and A is now [1,2].

  Tag : Array TwoPointers
 */
int rmvDup(int a[], unsigned int len)
{
    int cursor = 0;

    for (int i=1; i<len; i++) {
        if (a[cursor] != a[i]) {
            ++ cursor;
            if (cursor != i) {
                a[cursor] = a[i];                
            }
        }
    }

    return cursor+1;
}

void printArray(int a[], unsigned int len)
{
    for (int i=0; i<len; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}

/*
 * C++ version
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
            
        int cursor = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[cursor] != nums[i]) {
                nums[++cursor] = nums[i];
            }
        }
        
        return cursor+1;
    }
};

int main()
{
    int a[] = {1, 1, 1, 2, 3, 4, 4, 4, 4, 5, 6, 6, 7};
    int len = sizeof(a)/sizeof(a[0]);

    printArray(a, len);

    //int len1 = rmvDup(a, len);
    //printArray(a, len1);
    int len2 = rmvDup(a, len, 2);
    printArray(a, len2);
    
	return 0;
}

