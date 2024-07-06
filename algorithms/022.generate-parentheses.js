/**
 * @param {number} n
 * @return {string[]}
 */
let memo = [];

function generateParenthesis(n) {
	memo = [...Array(n + 1)]
			.map(() => Array.from({ length: n + 1 }, () => []));

	return subMemo(n, n, n);
}

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
