#
# [100] Same Tree
#
# https://leetcode.com/problems/same-tree
#
# Easy (45.94%)
# Total Accepted:    197614
# Total Submissions: 429740
# Testcase Example:  '[]\n[]'
#
# 
# Given two binary trees, write a function to check if they are equal or not.
# 
# 
# Two binary trees are considered equal if they are structurally identical and
# the nodes have the same value.
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p and q:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return p is q
