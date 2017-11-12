#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle
#
# Easy (37.76%)
# Total Accepted:    126061
# Total Submissions: 333754
# Testcase Example:  '0'
#
# Given numRows, generate the first numRows of Pascal's triangle.
# 
# 
# For example, given numRows = 5,
# Return
# 
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
# 
# 
#
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        for ii in range(numRows):
            result.append([1])
            for jj in range(1, ii+1):
                if ii == jj:
                    result[ii].append(1)
                else:
                    result[ii].append(result[ii-1][jj-1] + result[ii-1][jj])
        return result
