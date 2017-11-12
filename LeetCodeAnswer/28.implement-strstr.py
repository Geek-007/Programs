#
# [28] Implement strStr()
#
# https://leetcode.com/problems/implement-strstr
#
# Easy (27.61%)
# Total Accepted:    175505
# Total Submissions: 635714
# Testcase Example:  '""\n""'
#
# 
# Implement strStr().
# 
# 
# Returns the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.
# 
#
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(haystack) < len(needle):
            return -1
        elif len(needle) == 0:
            return 0

        diff = len(haystack) - len(needle)
        for ii in range(diff+1):
            if haystack[ii:ii+len(needle)] == needle:
                return ii
        return -1
