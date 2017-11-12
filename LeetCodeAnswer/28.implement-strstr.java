/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.61%)
 * Total Accepted:    175505
 * Total Submissions: 635714
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
public class Solution {
    public int strStr(String haystack, String needle) {
	    int l1 = needle.length();
	    int l2 = haystack.length();

	    if (l1 > l2)
		    return -1;
	    else if (l1 == 0)
		    return 0;

	    int diff = l2 - l1;
	    for(int ii=0; ii<=diff; ii++) {
	    	if(haystack.substring(ii, ii+l1).equals(needle))
			return ii;
	    }
	    return -1;
    }
}
