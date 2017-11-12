/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number
 *
 * Easy (34.67%)
 * Total Accepted:    203974
 * Total Submissions: 588068
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
bool isPalindrome(int x) {
	if(x < 0) return false;

	if(x < 10) return true;

	int count = 1;
	while(x / count >= 10)
		count = count * 10;

	while(x > 0){
		int left = x / count;
		int right = x % 10;
		if(left != right)
			return false;
		else {
			x = x % count;
			x = x / 10;
			count = count / 100;
		}
	}
	return true;
}
