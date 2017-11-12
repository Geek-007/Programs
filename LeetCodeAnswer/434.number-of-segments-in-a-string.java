/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string
 *
 * Easy (37.06%)
 * Total Accepted:    18472
 * Total Submissions: 49868
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
public class Solution {
    public int countSegments(String s) {
	    int count = 0;
	    for(int i=0; i<s.length(); i++){
		    if(s.charAt(i) != ' ' && (i == 0 || s.charAt(i-1) == ' ')){
			    count++;
		    }
	    }
	    return count;
    }
}
