/*
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree
 *
 * Easy (45.94%)
 * Total Accepted:    197614
 * Total Submissions: 429740
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two binary trees, write a function to check if they are equal or
 * not.
 * 
 * 
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 * 
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(q == null && p == null) return true;
	return p != null && q != null && q.val == p.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
