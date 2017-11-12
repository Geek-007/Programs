/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer
 *
 * Easy (44.81%)
 * Total Accepted:    144031
 * Total Submissions: 321367
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
public class Solution {
    public int romanToInt(String s) {
	    int num = 0;

	    Map<Character, Integer> table = new HashMap<Character, Integer>();
	    table.put('I', 1);
	    table.put('V', 5);
	    table.put('X', 10);
	    table.put('L', 50);
	    table.put('C', 100);
	    table.put('D', 500);
	    table.put('M',1000);
	    
	    int length = s.length();

	    if(length == 1){
		    num = table.get(s.charAt(0));
	    } else {
		    for(int ii=0; ii<length-1; ii++){
			    if(table.get(s.charAt(ii+1)) > table.get(s.charAt(ii)))
				    num = num - table.get(s.charAt(ii));
			    else
				    num = num + table.get(s.charAt(ii));
		    }
		    num = num + table.get(s.charAt(length-1));
	    }
	    return num;
    }
}
