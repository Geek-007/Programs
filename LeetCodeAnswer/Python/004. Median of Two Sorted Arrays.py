class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        combine = nums1 + nums2
        combine.sort()
        median = 0
        if len(combine) % 2 == 0:
            median = (combine[len(combine)/2] + combine[len(combine)/2-1])/2.0
        else:
            median = combine[len(combine)/2]
        return median