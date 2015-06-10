/*
  Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
  Author : Alex Xu
  Date   : June 10, 2015
  Problem:
  There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#inlcude <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        
        if (total % 2 == 1) { // odd number {1,2,3} -> 2
            return findKthSmallest(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total/2 + 1);
        } else { // even number {1, 2, 3, 4} -> (2+3)/2.0
            return (findKthSmallest(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total/2) + 
                    findKthSmallest(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total/2 + 1)) / 2.0;
        }
    }
    
    int findKthSmallest(vector<int>& A, int lowA, int lenA, vector<int>& B, int lowB, int lenB, int k) {
        // always assume nums1.size() < nums2.size()
        if (lenA > lenB)
            return findKthSmallest(B, lowB, lenB, A, lowA, lenA, k);
        
        // exit condition: m is empty or k==1    
        if (lenA == 0)
            return B[k-1];
        if (k == 1)
            return std::min(A[lowA], B[lowB]);
        
        // devide k into two parts, kA in A and kB in B, where (kA + Kb = k)
        int kA = std::min(k/2, int(A.size()));
        int kB = k - kA;
        
        if (A[lowA + kA-1] < B[lowB+kB-1]) // ignore A[lowA,...lowA+lenA]
            return findKthSmallest(A, lowA + kA, lenA - kA, B, lowB, lenB, k-kA);
        if (A[lowA+kA-1] > B[lowB+kB-1]) // ignore B[lowB,...lowB+lenB]
            return findKthSmallest(A, lowA, lenA, B, lowB + kB, lenB - kB, k-kB);
        else 
            return A[lowA+kA-1];
    }
    
private:
    double findMedianInSortedArray(vector<int>& v) {
        int n = v.size();
        if (n == 0)
            return 0;
        
        if (n % 2 == 0)
            return (v[n/2 - 1] + v[n/2]) / 2.0;
        else
            return v[n/2];
    }
};
