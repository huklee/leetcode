#include <iostream>
#include <vector>
#include <string>
using namespace std;

int* memo;

int getMemo(int i, int j, int n) { return memo[i*n + j]; }
void setMemo(int i, int j, int n, int val) { memo[i*n + j] = val; }

// JTD Study Code
int solve(int n, int cntOpen, int cntClose){
	// 01. base case
	if (cntOpen == n && cntClose == n)	return 1;

	// 02. edge case
	if (cntOpen > n || cntClose > n || cntOpen < cntClose) return 0;

	// 03. recall memo
	if (getMemo(cntOpen, cntClose, n) > 0)
		return getMemo(cntOpen, cntClose, n);
	else{
		// 04. recursive call	
		int result = solve(n, cntOpen + 1, cntClose) + solve(n, cntOpen, cntClose + 1);
		setMemo(cntOpen, cntClose, n, result);	
		return result;
	}
}

int generateParenthesis(int n) {
	memo = new int[(n + 1)*(n + 1)];
	memset(memo, -1, sizeof(int)*(n + 1)*(n + 1));
	return solve(n, 0, 0);
}

int main(){
	int n = 10;
	cout << generateParenthesis(n) << endl;
	return 0;
} 
