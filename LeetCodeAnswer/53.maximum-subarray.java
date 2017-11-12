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
public class Solution {
    public int maxSubArray(int[] nums) {
    	return FindMaxSubArray(0, nums.length-1, nums);
    }

    public int FindMaxSubArray(int low, int high, int[] nums) {
    	if(low == high) return nums[low];

	int mid = (low + high) / 2;

	int left_sum = FindMaxSubArray(low, mid, nums);
	int right_sum = FindMaxSubArray(mid+1, high, nums);
	int cross_sum = FindMaxCross(low, mid, high, nums);

	if(left_sum >= right_sum && left_sum >= cross_sum)
		return left_sum;
	else if (right_sum >= cross_sum && right_sum >= left_sum)
		return right_sum;
	else
		return cross_sum;
    }

    public int FindMaxCross(int low, int mid, int high, int [] nums){
    	int left = -2147483648;
	int tmp = 0;
	for(int ii=mid; ii>=low; ii--){
		tmp = tmp + nums[ii];
		if(tmp > left)
			left = tmp;
	}

	int right = -2147483648;
	tmp = 0;
	for(int ii=mid+1; ii<=high; ii++){
		tmp = tmp + nums[ii];
		if(tmp > right)
			right = tmp;
	}
	return left + right;
    }
}
