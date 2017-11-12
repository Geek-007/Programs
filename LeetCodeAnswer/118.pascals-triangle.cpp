/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * Easy (37.76%)
 * Total Accepted:    126061
 * Total Submissions: 333754
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
	    vector<vector<int>> result;
	    for(int ii=0; ii<numRows; ii++) {
		vector<int> row;
		for(int jj=0; jj<=ii; jj++) {
			if(jj == 0 || jj == ii) {
				row.push_back(1);
			} else {
				row.push_back(result[ii-1][jj-1] + result[ii-1][jj]);
			}
		}
		result.push_back(row);
	    }
	    return result;
    }
};
