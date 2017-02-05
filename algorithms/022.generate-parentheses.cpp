#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solve(int n, int cntOpen, int cntClose) {
	// 01. base case
	if (cntOpen == n && cntClose == n)	
		return vector<string>(1,"");

	// 02. edge case
	if (cntOpen > n || cntClose > n || cntOpen < cntClose) 
		return vector<string>();

	// 03. recursive call	
	vector<string> result, open_result, close_result;
	for (string s : solve(n, cntOpen + 1, cntClose))
		open_result.push_back("(" + s);
	for (string s : solve(n, cntOpen, cntClose + 1))
		close_result.push_back(")" + s);
	result.insert(result.begin(), open_result.begin(), open_result.end());
	result.insert(result.begin(), close_result.begin(), close_result.end());
	return result;
}

vector<string> generateParenthesis(int n) {
	return solve(n, 0, 0);
}
   
int main(){
	int n = 3;
	for (string s : generateParenthesis(n))
		cout << s << endl;
	return 0;
} 
