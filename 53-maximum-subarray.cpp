/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
    the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include "MyUtil.h"
using namespace fos;


class Solution {
public:
    /*
     * Scaning Algorithm:
     *     A negative value does not help for SUM. 
     */

    int maxSubArray4(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int i=0; i<nums.size(); i++) {
            if (currentSum < 0)
                currentSum = nums[i];
            else 
                currentSum += nums[i];

            maxSum = std::max(currentSum, maxSum);
        }

        return maxSum;
    }

public:
    /*
     * Dynamic programming
     *
     * The state formular is:
     *     f[i] - the MSS(Maximum Subarray Sum) of subarray a[0], a[1] ... a[i]
     * then
     *     f[i+1] = max(f[i] + a[i+1], a[i+1])
     * So
     *     max(f[0], f[1] ... f[n]) is the answer.
     *
     * Time: O(n), Space: O(1)
     */
    int maxSubArray3(vector<int>& nums) {
        int maxSum = INT_MIN;
        int f = 0;
        for (int i=0; i<nums.size(); i++) {
            f = std::max(f + nums[i], nums[i]);
            maxSum = std::max(f, maxSum);
        }

        return maxSum;
    }

public:
    /*
     * Devide and Conquer
     * Time: O(nlogn)
     */
    int maxSubArray2(vector<int>& nums) {
        return maxSubArray2(nums, 0, nums.size()-1);
    }
    int maxSubArray2(vector<int>& nums, int low, int high) {
        if (low == high)
            return nums[low];

        int mid = (low + high)/2;
        
        // the max sub array is in the left, low <= i <= j <= mid
        int maxSumLeft = maxSubArray2(nums, low, mid);
        // the max sub array is in the right, mid < i <= j <= high
        int maxSumRight = maxSubArray2(nums, mid+1, high);
        // the max sub array is crossing the middle, low <= i <= mid < j <= high
        int maxSumCross = maxSubArrrayCross(nums, low, mid, high);

        return max(max(maxSumLeft, maxSumRight), maxSumCross);
    }

private:
    /*
     * Time: O(n)
     */
    int maxSubArrrayCross(vector<int>& nums, int low, int mid, int high) {
        int maxSumCrossLeft = INT_MIN;
        int maxSumCrossRight = INT_MIN;
        
        int lowSub = low;
        int highSub = high;

        int maxSumTemp = 0;
        
        // left max sub array
        for (int i=mid; i>= low; i--) {
            maxSumTemp += nums[i];
            if (maxSumTemp > maxSumCrossLeft) {
                maxSumCrossLeft = maxSumTemp;
                lowSub = low;
            }
        }

        maxSumTemp = 0;
        // right max sub array
        for (int j=mid+1; j<= high; j++) {
            maxSumTemp += nums[j];
            if (maxSumTemp > maxSumCrossRight) {
                maxSumCrossRight = maxSumTemp;
                highSub = high;
            }
        }

        return maxSumCrossLeft + maxSumCrossRight;
    }

public:
    /*
     * Brute-Force Algorithm
     * Time: O(n^2)
     */
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int low = 0;
        int high = 0;

        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                    low = i;
                    high = j;
                }
            }
            sum = 0; // reset for each loop
        }

        cout << "max=" << max << " i=" <<low << " j=" <<high <<endl;
        return max;
    }
};


int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(a) / sizeof(a[0]);

    fos::printArray(a, len);

    vector<int> v;
    for (int i=0; i<len; i++)
        v.push_back(a[i]);

    Solution s;
    cout << s.maxSubArray3(v) << endl;

    return 0;
}

