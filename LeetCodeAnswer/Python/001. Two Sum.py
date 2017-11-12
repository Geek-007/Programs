class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        for ii in range(len(nums)):
            complement = target - nums[ii]
            if complement in lookup.keys() and lookup[complement] != ii:
                return [lookup.get(complement), ii]
            lookup[nums[ii]] = ii