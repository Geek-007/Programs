class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        place = len(digits) - 1
        while carry != 0:
            digits[place] = digits[place] + carry
            if digits[place] / 10 != 0:
                carry = digits[place] / 10
                digits[place] = digits[place] % 10
                if place == 0 and carry != 0:
                    digits.insert(0, carry)
                    carry = 0
                place = place - 1
            else:
                digits[place] = digits[place] % 10
                carry = digits[place] / 10
        return digits