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
public class Solution {
    public List<List<Integer>> generate(int numRows) {
	    List<List<Integer>> result = new ArrayList<List<Integer>>();
	    for(int ii=0; ii<numRows; ii++) {
	    	List<Integer> row = new ArrayList<Integer>();
		for(int jj=0; jj<=ii; jj++) {
			if(jj == 0 || jj == ii) {
				row.add(1);
			} else {
				row.add(result.get(ii-1).get(jj-1) + result.get(ii-1).get(jj));
			}
		}
		result.add(row);
	    }
	    return result;
    }
}
