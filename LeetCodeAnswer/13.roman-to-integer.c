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
int toNumber(char ch) {  
	switch (ch) { 
		case 'I': return 1;  
		case 'V': return 5;
		case 'X': return 10;  
		case 'L': return 50;  
		case 'C': return 100;  
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
} 

int romanToInt(char* s) {
	int num = 0;
	int len = 0;
	while(s[len++] != '\0'){}
	
	len--;

	if(len == 1){
		num = num + toNumber(s[0]);
	}else{
		for(int ii=0; ii<len-1; ii++){
			if(toNumber(s[ii+1]) > toNumber(s[ii]))
				num = num - toNumber(s[ii]);
			else
				num = num + toNumber(s[ii]);
		}
		num = num + toNumber(s[len-1]);
	}
	return num;
}
