/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element
 *
 * Easy (38.12%)
 * Total Accepted:    189787
 * Total Submissions: 497628
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 */
int removeElement(int* nums, int numsSize, int val) {
	int mylength = 0;
	for(int ii=0; ii<numsSize; ii++) {
		if(nums[ii] != val)
			nums[mylength++] = nums[ii];
	}
	return mylength;
}
