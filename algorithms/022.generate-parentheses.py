# real leetcode solution
def subMemo(n, cntOpen, cntClose):
	global memo
	# 00. base case
	if cntOpen == n and cntClose == n:
		return [""] 
	
	# 01. edge case
	if cntOpen > n or cntClose > n or cntOpen < cntClose:
		return []

	if memo[cntOpen][cntClose] != []:
		return memo[cntOpen][cntClose]

	# 02. recursive call
	openResult = ["(" + x for x in subMemo(n, cntOpen + 1, cntClose)]
	closeResult = [")" + x for x in subMemo(n, cntOpen, cntClose + 1)]	
	result = openResult + closeResult
	memo[cntOpen][cntClose] = result
	return result

def subNomemo(n, cntOpen, cntClose):
	# 00. final case
	if cntOpen == n and cntClose == n:
		return [""] 
	
	# 01. edge case
	if cntOpen > n or cntClose > n or cntOpen < cntClose:
		return []

	# 02. recursive call	
	openResult = ["(" + x for x in subNomemo(n, cntOpen + 1, cntClose)]
	closeResult = [")" + x for x in subNomemo(n, cntOpen, cntClose + 1)]	
	result = openResult + closeResult
	return result


def solve(n):
	return subMemo(n, 0, 0);	

n = 5 
memo = [[[] for x in range(n+1)] for i in range(n+1)]
print(solve(n))

# JTD Study Code
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
