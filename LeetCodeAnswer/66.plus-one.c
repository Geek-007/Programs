/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * Easy (37.89%)
 * Total Accepted:    162438
 * Total Submissions: 428565
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int carry = 1;
	int idx = digitsSize - 1;
	while(carry != 0) {
		digits[idx] = digits[idx] + carry;
		if (digits[idx] > 9) {
			digits[idx] = digits[idx] % 10;
			idx--;
		} else {
			carry = 0;
		}

		if(idx == -1)
			break;
	}

	if (digits[0] == 0 && carry == 1) {
		int* result = malloc(sizeof(int)*(digitsSize+1));
		for(int ii=0; ii<digitsSize; ii++) {
			result[ii+1] = digits[ii];
		}
		result[0] = 1;
		*returnSize = digitsSize + 1;
		return result;
	} else {
		*returnSize = digitsSize;
		return digits;
	}
}
