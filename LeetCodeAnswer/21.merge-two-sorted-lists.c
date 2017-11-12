/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Easy (38.62%)
 * Total Accepted:    213737
 * Total Submissions: 553356
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
 	if(l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}else{
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}
}