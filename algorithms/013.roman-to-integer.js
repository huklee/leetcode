/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
	const romanDict = {
		"M": 1000,
		"D": 500,
		"C": 100,
		"L": 50,
		"X": 10,
		"V": 5,
		"I": 1
	};
	
	let result = 0;
	for (let i = 0; i < s.length - 1; i++) {
		const prevChar = s[i];
		const nextChar = s[i + 1];
		// 01. next char is bigger than previous one, this is the minus operation
		if (romanDict[prevChar] < romanDict[nextChar]) {
			result -= romanDict[prevChar];
		}
		// 02. otherwise, it's addition
		else {
			result += romanDict[prevChar];
		}
	}
	// for the last char, just plus
	result += romanDict[s[s.length - 1]];
	return result;
};
