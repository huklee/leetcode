class Solution {
public:
int popNumber(vector<int>& nums1, vector<int>& nums2, int& i1, int& i2){
	if (i1 < nums1.size() && i2 < nums2.size()){
    	if (nums1[i1] < nums2[i2])
			return nums1[i1++];
		else	
		    return nums2[i2++];
	}
	else if (i1 < nums1.size())
		return nums1[i1++];
	else if (i2 < nums2.size())
		return nums2[i2++];
	return 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i1=0, i2=0;
	int n = nums1.size() + nums2.size();
	int m = n / 2;
	int val1 = 0, val2 = 0;
	
	// 01. pick the 2 mininum values for m times.
	for (int i = 0; i <= m; i++){
	    val1 = val2;
        val2 = popNumber(nums1, nums2, i1, i2);
	}

    // 02. Calculate the final midium value
	double r = (n % 2 == 0) ? (val1 + val2) / 2.0f : val2;
	return r;
}
};
