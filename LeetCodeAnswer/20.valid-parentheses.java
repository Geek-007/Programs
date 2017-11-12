/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (32.95%)
 * Total Accepted:    193064
 * Total Submissions: 585816
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
public class Solution {
    public boolean isValid(String s) {
	Stack <Character> stack = new Stack();
	for(int ii=0; ii<s.length(); ii++){
		if(s.charAt(ii) == '(' || s.charAt(ii) == '[' || s.charAt(ii) == '{')
			stack.push(s.charAt(ii));
		if(s.charAt(ii) == ')' && (stack.empty() || stack.pop() != '('))
			return false;
		if(s.charAt(ii) == ']' && (stack.empty() || stack.pop() != '['))
			return false;
		if(s.charAt(ii) == '}' && (stack.empty() || stack.pop() != '{'))
			return false;
	}
	return stack.empty();
    }
}
