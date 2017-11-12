/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * Easy (32.72%)
 * Total Accepted:    490484
 * Total Submissions: 1499092
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int*)malloc(2*sizeof(int)); 
    for(int ii=0; ii<numsSize; ii++){
	    for(int jj=ii+1; jj<numsSize; jj++){
		    if(nums[jj] + nums[ii] == target){
			    result[0] = ii;
			    result[1] = jj;
		    }
	    }
    }	
    return result;
}
