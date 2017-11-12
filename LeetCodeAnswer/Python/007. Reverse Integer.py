class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sum = 0
        flag = 1
        maxint = 2147483647
        minint = -2147483648
        print maxint
        if x < 0:
            flag = 0
            x = -x
        xstring = str(x)
        for ii in range(len(xstring)):
            sum = sum + int(xstring[ii])*pow(10,ii)
        if flag == 0:
            sum = -sum
        if sum > maxint or sum < minint:
            sum = 0
        return sum
        