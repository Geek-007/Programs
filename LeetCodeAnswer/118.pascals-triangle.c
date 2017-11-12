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
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
	int** result = (int**)malloc(sizeof(int*) * numRows);
	*columnSizes = (int*)malloc(sizeof(int) * numRows);

	for(int ii=0; ii<numRows; ii++) {
		(*columnSizes)[ii] = ii+1;
		result[ii] = (int*)malloc(sizeof(int) * (ii+1));
		for(int jj=0; jj<=ii; jj++) {
			if(jj == 0 || jj == ii) {
				result[ii][jj] = 1;
			} else {
				result[ii][jj] = result[ii-1][jj-1] + result[ii-1][jj];
			}
		}

	}
	return result;
}
