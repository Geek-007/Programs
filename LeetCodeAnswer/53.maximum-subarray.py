#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray
#
# Easy (39.27%)
# Total Accepted:    187920
# Total Submissions: 478573
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# 
# Find the contiguous subarray within an array (containing at least one number)
# which has the largest sum.
# 
# 
# For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
# the contiguous subarray [4,-1,2,1] has the largest sum = 6.
# 
# 
# click to show more practice.
# 
# More practice:
# 
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
# 
#
class Solution(object):
    def FindMaxSubArray(self, low, high, nums):
        if low == high:
            return low, high, nums[low]
        else:
            mid = (high + low) / 2
            left_low, left_high, left_sum = self.FindMaxSubArray(low, mid, nums)
            right_low, right_high, right_sum = self.FindMaxSubArray(mid+1, high, nums)
            center_low, center_high, center_sum = self.FindMaxCrossingSubArray(low, mid, high, nums)
            if left_sum >= right_sum and left_sum >= center_sum:
                return left_low, left_high, left_sum
            if right_sum >=left_sum and right_sum >= center_sum:
                return right_low, right_high, right_sum
            return center_low, center_high, center_sum

    def FindMaxCrossingSubArray(self, low, mid, high, nums):
        left_sum = -2147483648
        tmp = 0
        left = low
        interval = range(low, mid+1)
        interval.reverse()
        for ii in interval:
            tmp = tmp + nums[ii]
            if tmp > left_sum:
                left_sum = tmp
                left = ii
        right_sum = -2147483648
        tmp = 0
        right = high
        interval = range(mid+1, high+1)
        for jj in interval:
            tmp = tmp + nums[jj]
            if tmp > right_sum:
                right_sum = tmp
                right = jj
        return left, right, left_sum + right_sum

    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low, high, max_sum = self.FindMaxSubArray(0, len(nums)-1, nums)
        return max_sum
