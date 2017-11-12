class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        nums = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
        sides = 9
        small = 3
        for idx in range(sides):
            for idy in range(sides):
                if board[idx][idy] in nums:
                    tmp = board[idx][idy]
                    board[idx][idy] = 'X'
                    for ii in range(sides):
                        if board[ii][idy] == tmp:
                            return False
                        if board[idx][ii] == tmp:
                            return False
                    for ii in range(small):
                        for jj in range(small):
                            if board[idx/small*small+ii][idy/small*small+jj] == tmp:
                                return False
                    board[idx][idy] = tmp
        return True
                    