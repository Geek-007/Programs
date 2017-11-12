#
# [371] Sum of Two Integers
#
# https://leetcode.com/problems/sum-of-two-integers
#
# Easy (51.19%)
# Total Accepted:    65663
# Total Submissions: 128290
# Testcase Example:  '1\n2'
#
# Calculate the sum of two integers a and b, but you are not allowed to use the
# operator + and -.
# 
# Example:
# Given a = 1 and b = 2, return 3.
# 
# 
# Credits:Special thanks to @fujiaozhu for adding this problem and creating all
# test cases.
#
class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """ 
        MAX_INT = 0x7FFFFFFF
        MASK = 0x100000000
        while b:
            a, b = (a ^ b) % MASK, ((a & b) << 1) % MASK
        return a if a <= MAX_INT else ~((a & MAX_INT) ^ MAX_INT)
