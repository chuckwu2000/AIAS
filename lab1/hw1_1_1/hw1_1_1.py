class Solution:
	def reverseBits(n):
		ans = 0
		#Input length must be equal to 32
		for i in range(32):
			#In every iteration, left shift one bit and append a reverse bit
			ans = (ans << 1) | (n & 1)
			n >>= 1
		return ans

	print(reverseBits(0b00000010100101000001111010011100))
