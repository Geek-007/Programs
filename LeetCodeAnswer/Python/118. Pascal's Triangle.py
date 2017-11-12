class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        output = []
        for ii in range(numRows):
            output.append([1])
            for jj in range(1, ii+1):
                if ii == jj:
                    output[ii].append(1)
                else:
                    output[ii].append(output[ii-1][jj-1] + output[ii-1][jj])
        return output
        