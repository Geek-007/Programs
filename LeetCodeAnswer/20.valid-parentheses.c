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
bool isValid(char* s) {
	char* stack;
	int top_stack = -1;

	size_t n = strlen(s);

	stack = (char*) malloc(sizeof(char*)*(n+1));

	for(int ii=0; ii<n; ii++){
		switch(s[ii]){
			case '{':
			case '(':
			case '[': stack[++top_stack] = s[ii]; break;
			case '}': if(top_stack == -1 || stack[top_stack] != '{') return false; else top_stack--; break;
			case ']': if(top_stack == -1 || stack[top_stack] != '[') return false; else top_stack--; break;
			case ')': if(top_stack == -1 || stack[top_stack] != '(') return false; else top_stack--; break;
			defaulst: ;
		}
	}
	return top_stack == -1;
}
