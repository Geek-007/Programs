class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        flag = 1
        count = 10
        if x < 0:
            return False
        if x < 10:
            return True
        while x / count >= 10:
            count = count * 10
        while x > 0:
            leftnumber = x / count
            rightnumber = x % 10
            if leftnumber != rightnumber:
                return False
            else:
                x = x % count
                x = x / 10
                count = count / 100
        return True
        