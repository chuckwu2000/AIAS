class Solution(object):
	def isValidSudoku(board):
		#Check whether have repeat element
		def repeat_appear(num_list):
			count = set()
			for num in num_list:
				if num != '.':
					if num in count:
						return True
					count.add(num)
			return False

		def check_row(i):
			return repeat_appear(board[i])

		def check_col(j):
			num_list = []
			for i in range(9):
				num_list.append(board[i][j])
			return repeat_appear(num_list)

		def check_square(x, y):
			num_list = []
			for i in range(x, x + 3):
				for j in range(y, y + 3):
					num_list.append(board[i][j])
			return repeat_appear(num_list)

		#check row
		for i in range(9):
			if check_row(i):
				return False

		#checl col
		for i in range(9):
			if check_col(i):
				return False

		#check square
		for i in range(0, 9, 3):
			for j in range(0, 9, 3):
				if check_square(i, j):
					return False
		return True		

	print(isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]))
	print(isValidSudoku([["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]))
