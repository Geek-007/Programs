#
# [66] Plus One
#
# https://leetcode.com/problems/plus-one
#
# Easy (37.89%)
# Total Accepted:    162438
# Total Submissions: 428565
# Testcase Example:  '[0]'
#
# Given a non-negative integer represented as a non-empty array of digits, plus
# one to the integer.
# 
# You may assume the integer do not contain any leading zero, except the number
# 0 itself.
# 
# The digits are stored such that the most significant digit is at the head of
# the list.
#
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        idx = len(digits) - 1
        while carry != 0:
            digits[idx] = digits[idx] + carry
            if digits[idx] > 9:
                digits[idx] = digits[idx] % 10
                idx = idx - 1
            else:
                carry = 0

            if idx == -1:
                break;
        if digits[0] == 0 and carry == 1:
            digits.insert(0, 1)
        return digits
