/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.17%)
 * Total Accepted:    168338
 * Total Submissions: 539968
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize) {
	char* result = strs[0];
	if(strsSize == 0) return "";
	for(int ii=0; ii<strsSize; ii++) {
		int jj=0; 
		while(result[jj] && strs[ii][jj] && result[jj]==strs[ii][jj]) jj++;
		result[jj]=0;
	}
	return result;
}
