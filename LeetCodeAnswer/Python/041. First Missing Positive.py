class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == [] or max(nums) <= 0:
            return 1
        length = len(nums)
        maxnums = max(nums)
        for ii in range(1, length+2):
            if ii in nums and ii <= maxnums:
                continue
            else:
                return ii
        