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
public class Solution {
    public String longestCommonPrefix(String[] strs) {
	    String result = "";
	    if(strs.length == 0)
		    return result;
	    for(int ii=0; ii<strs[0].length(); ii++) {
	    	for(int jj=1; jj<strs.length; jj++) {
			if(ii >= strs[jj].length() || strs[jj].charAt(ii) != strs[0].charAt(ii))
				return result;
		}
		result = result + strs[0].charAt(ii);
	    }
	    return result;
    }
}
