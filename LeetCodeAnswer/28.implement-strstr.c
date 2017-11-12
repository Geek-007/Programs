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
char* substr(char* haystack, int idx1, int len) {
	char* result = (char*)malloc(sizeof(char)*(len));
	for(int ii=0; ii<len; ii++)
		result[ii] = haystack[ii+idx1];
	return result;
}

int strStr(char* haystack, char* needle) {
	int l1 = strlen(haystack);
	int l2 = strlen(needle);

	if(l2 > l1)
		return -1;
	else if(l2 == 0)
		return 0;

	int diff = l1 - l2;
	for(int ii=0; ii<=diff; ii++) {
		if(strcmp(substr(haystack, ii, l2), needle) == 0)
			return ii;
	}
	return -1;
}
