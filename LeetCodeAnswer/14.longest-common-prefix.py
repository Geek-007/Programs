#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix
#
# Easy (31.17%)
# Total Accepted:    168338
# Total Submissions: 539968
# Testcase Example:  '[]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
#
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result = ''
        if not strs:
            return result
        for ii in range(len(strs[0])):
            for jj in range(1, len(strs)):
                if ii >= len(strs[jj]) or strs[0][ii] != strs[jj][ii]:
                    return result;
            result = result + strs[0][ii]
        return result
        
