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
import java.util.Arrays;
public class Solution {
    public int[] twoSum(int[] nums, int target) {
	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
	int [] result = new int [2];
    	for(int ii=0; ii<nums.length; ii++){
		int compliment = target - nums[ii];
		if(map.containsKey(compliment) && map.get(compliment) != ii){
			result[0] = ii;
			result[1] = map.get(compliment);
		}
		map.put(nums[ii], ii);
	}	    
	Arrays.sort(result);
	return result;
    }
}
