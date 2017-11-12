#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses
#
# Easy (32.95%)
# Total Accepted:    193064
# Total Submissions: 585816
# Testcase Example:  '"["'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# The brackets must close in the correct order, "()" and "()[]{}" are all valid
# but "(]" and "([)]" are not.
# 
#
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for ii in range(len(s)):
            if s[ii] == '(' or s[ii] == '{' or s[ii] == '[':
                stack.append(s[ii])
            if s[ii] == ')' and (len(stack) == 0 or stack.pop() != '('):
                return False
            if s[ii] == '}' and (len(stack) == 0 or stack.pop() != '{'):
                return False
            if s[ii] == ']' and (len(stack) == 0 or stack.pop() != '['):
                return False
        if len(stack) == 0:
            return True
        else:
            return False
