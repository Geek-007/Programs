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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
	    if(q == NULL && p == NULL) return true;
	    return p != NULL && q != NULL && p->val == q->val && isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
};
