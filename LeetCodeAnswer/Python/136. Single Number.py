class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        results = 0
        for ii in range(len(nums)):
            results = results ^ nums[ii]
        return results