/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
	const words = s.trim().split(' ').filter(x => x.length > 0);
	return words[words.length - 1].length;
};
