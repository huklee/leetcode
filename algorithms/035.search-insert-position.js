/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
	let left = 0, right = nums.length - 1;
	if(nums[right] < target)
		return right + 1;
	
	while (left < right){
		let mid = (left + right)/2 | 0;

		if (target <= nums[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
};
