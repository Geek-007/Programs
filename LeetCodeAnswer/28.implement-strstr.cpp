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
class Solution {
public:
    int strStr(string haystack, string needle) {
	    int l1 = haystack.size();
	    int l2 = needle.size();

	    if(l1 < l2)
		    return -1;
	    else if(l2 == 0)
		    return 0;

	    int diff = l1 - l2;
	    for(int ii=0; ii<=diff; ii++) {
	    	if(haystack.substr(ii, l2) == needle)
			return ii;
	    }
	    return -1;
    }
};
