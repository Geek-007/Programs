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
class Solution {
public:
    bool isValid(string s) {
	  stack<char> myStack;
	  for(char& ch : s){
		  switch(ch){
		  	case '(': 
			case '{': 
			case '[': myStack.push(ch); break;
			case ')': if(myStack.empty() || myStack.top() != '(') return false; else myStack.pop(); break;
			case '}': if(myStack.empty() || myStack.top() != '{') return false; else myStack.pop(); break;
			case ']': if(myStack.empty() || myStack.top() != '[') return false; else myStack.pop(); break;
			default: ;
		  }
	  }
	  return myStack.empty();
    }
};
