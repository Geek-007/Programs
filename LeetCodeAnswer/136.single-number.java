/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number
 *
 * Easy (53.75%)
 * Total Accepted:    210684
 * Total Submissions: 391927
 * Testcase Example:  '[1]'
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
public class Solution {
    public int singleNumber(int[] nums) {
	    int result = 0;
	    for(int ii=0; ii<nums.length; ii++) {
	    	result ^= nums[ii];
	    }
	    return result;
    }
}
