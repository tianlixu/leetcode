##
# Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
# Author : Alex Xu
# Date   : Feb 20, 2018
# Problem:
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#
# Your runtime beats 98.63 % of python3 submissions.
##
class Solution:
        def findMedianSortedArrays(self, nums1, nums2):
            """
            :type nums1: List[int]
            :type nums2: List[int]
            :rtype: float
            """
            total = len(nums1) + len(nums2)
            if total % 2 == 1:
                # odd number [1, 2, 3, 4, 5] -> list[5/2] = list[2] = 3: index 2 is the 3rd
                return self.findKthSmallest(nums1, nums2, total//2 + 1)
            else:
                # even number [1, 2, 3, 4] -> (list[4/2] -1 + list[4/2])/2.0 = (list[1] + list[2])/2.0, index 1 is the 2nd and index 2 is the 3rd
                return (self.findKthSmallest(nums1, nums2, total//2) + self.findKthSmallest(nums1, nums2, total//2 + 1)) / 2.0
            
        def findKthSmallest(self, a, b, k):
            """
            :type a: list[int]
            :type b: list[int]
            :type k: int
            """
            if len(a) > len(b):
                return self.findKthSmallest(b, a, k)
            
            # exit condition: a is empty or k==1
            if not a:
                return b[k-1]
            if k == 1:
                return min(a[0], b[0])
            
            # devide k into two parts ka elements in a and kb elements in b, where k = ka + kb
            ka = min(k//2, len(a))
            kb = k - ka
            
            if a[ka - 1] < b[kb - 1]:
                return self.findKthSmallest(a[ka:], b[:kb], kb) # ignore a[:ka]
            elif a[ka -1] > b[kb - 1]:
                return self.findKthSmallest(a[:ka], b[kb:], ka) # ignore a[:kb]
            else:
                return a[ka-1]; # or return b[k-1]
