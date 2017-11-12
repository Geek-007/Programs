#
# [26] Remove Duplicates from Sorted Array
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-array
#
# Easy (35.51%)
# Total Accepted:    220052
# Total Submissions: 619603
# Testcase Example:  '[]'
#
# 
# Given a sorted array, remove the duplicates in place such that each element
# appear only once and return the new length.
# 
# 
# Do not allocate extra space for another array, you must do this in place with
# constant memory.
# 
# 
# 
# For example,
# Given input array nums = [1,1,2],
# 
# 
# Your function should return length = 2, with the first two elements of nums
# being 1 and 2 respectively. It doesn't matter what you leave beyond the new
# length.
# 
#
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)

        idx = 1
        for ii in range(1, len(nums)):
            if nums[ii] != nums[ii-1]:
                nums[idx] = nums[ii]
                idx = idx + 1
        return idx
