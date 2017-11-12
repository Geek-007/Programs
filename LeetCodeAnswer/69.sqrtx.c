/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * Easy (27.47%)
 * Total Accepted:    147927
 * Total Submissions: 538407
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */
int mySqrt(int x) {
	long ans = x;
	while(ans * ans > x){
		ans = (ans + x / ans) / 2;
	}
	return ans;
}
