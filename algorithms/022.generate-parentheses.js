/**
 * @param {number} n
 * @return {string[]}
 */
let memo = [];

function generateParenthesis(n) {
	memo = [...Array(n + 1)].map(() => Array(n + 1).fill([]));
	return subMemo(n, n, n);
}

// All possibilities of parenthesis using cntOpen * opening and cntOpen * closing
function subMemo(n, cntOpen, cntClose) {
	// 00. base case
	if (cntOpen === 0 && cntClose === 0) {
		return [""];
	}
	
	// 01. edge case
	if (cntOpen < 0 || cntClose < 0 || cntOpen < cntClose) {
		return [];
	}

	if (memo[cntOpen][cntClose].length > 0) {
		return memo[cntOpen][cntClose];
	}

	// 02. recursive call
	let openResult = subMemo(n, cntOpen - 1, cntClose).map(x => x + "(");
	let closeResult = subMemo(n, cntOpen, cntClose - 1).map(x => x + ")");
	let result = openResult.concat(closeResult);
	memo[cntOpen][cntClose] = result;
	return result;
}
