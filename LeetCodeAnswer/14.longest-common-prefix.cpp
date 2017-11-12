/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.17%)
 * Total Accepted:    168338
 * Total Submissions: 539968
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	    string result = "";
	    if(strs.size() == 0)
		    return result;
	    for(int ii=0; ii<strs[0].size(); ii++) {
	    	for(int jj=1; jj<strs.size(); jj++) {
			if(ii>=strs[jj].size() || strs[jj][ii] != strs[0][ii])
				return result;
		}
		result = result + strs[0][ii];
	    }
	    return result;
    }
};
