/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray
 *
 * Easy (39.27%)
 * Total Accepted:    187920
 * Total Submissions: 478573
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 * 
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
#define max(x,y)  ( x > y ? x : y )
int maxSubArray(int* nums, int numsSize) {
	int ans = nums[0];
	int tmp = 0;
	for(int ii=0; ii<numsSize; ii++){
		tmp = tmp + nums[ii];
		ans = max(ans, tmp);
		tmp = max(tmp, 0);
	}
	return ans;
}
