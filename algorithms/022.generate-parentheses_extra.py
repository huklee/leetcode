def sub(n, memo, cntOpen, cntClose):
	# 00. edge case for
	if cntOpen > n or cntClose > n or cntOpen < cntClose:
		return 0
	if cntOpen == n and cntClose == n:
		return 1 

	# 01. recall the memo
	if memo[cntOpen][cntClose] > 0:
		return memo[cntOpen][cntClose]
	else:
		result = sub(n, memo, cntOpen + 1, cntClose) + sub(n, memo, cntOpen, cntClose + 1)
	
		# 02. save the memo & recursive call
		memo[cntOpen][cntClose] = result
		return result

def solve_(n):
	memo = [[-1 for x in range(n+1)] for i in range(n+1)]
	memo[0][0] = 0
	return sub(n, memo, 0, 0)

def sub2(n, cntOpen, cntClose, s):
	# 00. final case
	if cntOpen == n and cntClose == n:
		print s
	
	# 01. edge case
	if cntOpen > n or cntClose > n or cntOpen < cntClose:
		return
	sub2(n, cntOpen + 1, cntClose, s + "(")
	sub2(n, cntOpen, cntClose + 1, s + ")")

def solve(n):
	return sub2(n, 0, 0, "");	

print(solve(3))
