/*
 Source : https://leetcode.com/problems/trapping-rain-water/description/
 Author : Alex Xu
 Date   : Nov 20, 2017
 Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Solution:
Tag: divide and conquer, two pointers, stack
*/

/*
 * Divide and conquer
 * I was tring to veriy that this is a solution. I thought it would be rejected due to the performance issue.
 * A suprise that it was ACCEPTED. 
 * The runtime of this solution beats 20% of java submissions
 */
class Solution {
    public int trap(int[] height) {
        if (height.length <3) {
            return 0;
        }
        return trap(height, 0, height.length-1);
    }
    
    public int trap(int[] height, int left, int right) {
        int indexMax = findMax(height, left, right);
        if (indexMax == -1) {
            return trapSum(height, left, right);
        }
        return trap(height, left, indexMax) + trap(height, indexMax, right);        
    }
    
    // All the values in the array a are smaller than both a[i] and a[j]
    public int trapSum(int[] a, int i, int j) {
        int sum = Math.min(a[i], a[j]) * (j - i - 1);
        while (++i < j) {
            sum -= a[i];
        }
        
        return sum;
    }
    
    // find the index of max
    public int findMax(int[] a, int l, int r) {
        int index = -1;
        
        int max = Math.min(a[l], a[r]);
        while(++l < r) {
            if (a[l] > max) {
                max = a[l];
                index = l;
            }
        }
        
        return index;
    }
}


/*
 * two pointers, quite effective solution
 * the runtime of this solution beats 90% of java submissions
 */
class Solution {
    public int trap(int[] height) {
        int sum = 0;
        int maxofmin = 0;
        int i = 0;
        int j = height.length - 1;

        while (i < j) {
            if (height[i] < height[j]) {
                if (height[i] < maxofmin) {
                    sum += maxofmin - height[i];
                } else {
                    maxofmin = height[i];
                }
                ++ i;
            } else {
                if (height[j] < maxofmin) {
                    sum += maxofmin - height[j];
                } else {
                    maxofmin = height[j];
                }
                -- j;
            }
        }

        return sum;
    }
}

class Solution {                                                                               
    public int trap(int[] height) {                                                            
        int sum = 0;             
        
        int min = 0;
        int maxofmin = 0;                                                                      
        int i = 0;                                                                             
        int j = height.length - 1;                                                             
        while (i < j) {                                                                        
            if (height[i] < height[j]) {
                min = height[i];                                                           
                ++ i;                                                                          
            } else {                                                                           
                min = height[j];                                                                           
                -- j;                                                                          
            }
            
            if (min < maxofmin) {
                sum += maxofmin - min;                                               
            } else {                                                                       
                maxofmin = min;                                                      
            }  
        }                                                                                      
        return sum;                                                                            
    }                                                                                          
} 