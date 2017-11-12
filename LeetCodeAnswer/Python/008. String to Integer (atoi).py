class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        template = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
        maxint = 2147483647
        minint = -2147483648
        if len(str) == 1 and str[0] not in template:
            return 0
        elif len(str) == 1 and str[0] in template:
            return int(str[0])
        elif str == None or str == "" or (str[0] not in template and str[0] != "+" and str[0] != "-") or (str[0] not in template and str[1] not in template):
            return 0
        output = []
        sum = 0
        flag = 0
        if str[0] == "+":
            flag = 1
        if str[0] == "-":
            flag = -1
        for ii in range(len(str)):
            if str[ii] in template:
                output.append(int(str[ii]))
                if ii == len(str) - 1 or str[ii+1] == None or str[ii+1] not in template:
                    break
            else:
                continue
        for ii in range(len(output)):
            sum = sum + output[ii]*pow(10, len(output) - ii - 1)
        if flag !=0:
            sum = sum * flag
        if sum > maxint:
            return maxint
        if sum < minint:
            return minint
        return sum