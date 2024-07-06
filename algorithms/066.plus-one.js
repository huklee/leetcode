/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
	for (let i = digits.length - 1; i >= 0; i--){
		if (digits[i] < 9){
			digits[i]++;
			return digits;
		}
		else{
			digits[i] = 0;
		}
	}
	return [1, ...digits];
};

var plusOneWithIntegerRage = function(digits) {
	let num = parseInt(digits.join('')) + 1
	return Array.from(num.toString()).map(Number);
};
