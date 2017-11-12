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
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	 map<int, int> myMap;
	 vector<int> result;
	 for (int i = 0; i < nums.size(); i++) {
		 myMap[nums[i]] = i;
	 }
	 for(int ii=0; ii<nums.size(); ii++){
		 int compliment = target - nums[ii];
		 if(myMap.find(compliment) != myMap.end() && myMap[compliment] != ii){
			result.push_back(ii);
			result.push_back(myMap[compliment]);
			break;
		 }
	 }
	 return result;
    }
};
