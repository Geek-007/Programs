#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum
#
# Easy (32.72%)
# Total Accepted:    490484
# Total Submissions: 1499092
# Testcase Example:  '[3,2,4]\n6'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
# 
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
# 
# 
# Example:
# 
# Given nums = [2, 7, 11, 15], target = 9,
# 
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# 
# 
#
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        allnums = {}
        for ii in range(len(nums)):
            complement = target - nums[ii]
            if complement in allnums.keys() and allnums[complement] != ii:
                return [allnums.get(complement), ii]
            allnums[nums[ii]] = ii
