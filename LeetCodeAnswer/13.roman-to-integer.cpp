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
class Solution {
public:
    int romanToInt(string s) {
	    int num = 0;
	    map<char, int> myMap;
	    myMap['I'] = 1;
	    myMap['V'] = 5;
	    myMap['X'] = 10;
	    myMap['L'] = 50;
	    myMap['C'] = 100;
	    myMap['D'] = 500;
	    myMap['M'] = 1000;

	    int length = s.length();

	    if(length == 1){
		    num = myMap[s[0]];
	    }else{
		    for(int ii=0; ii<length-1; ii++){
			    if(myMap[s[ii+1]] > myMap[s[ii]])
				    num = num - myMap[s[ii]];
			    else
				    num = num + myMap[s[ii]];
		    }
		    num = num + myMap[s[length-1]];
	    }
	    return num;
    }
};
