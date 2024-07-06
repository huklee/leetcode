/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
	if (x < 0){
		return false;
	}
	let reverseString = x.toString().split('').reverse().join('');
	if (reverseString != x){
		return false;
	}
	return true;
};

var isPalindromeTerse = function(x) {
	return x.toString().split('').reverse().join('') === x+'';
};
