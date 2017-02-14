#include <string>
#include <iostream>
using namespace std;

string getMaxPalOdd(string s){
	// Manacher's algorithm for Odd palindromes : O(n) 
	// 00. initialization
	int pivot = -1, max_range = -1, pal, *A = new int[s.size()];

	// 01. mid point progress
	for (int mid = 0; mid < s.size(); mid++){
		// 02. set the pre-minimum value fromt the range
		if (mid <= max_range)
			pal = min(max_range - mid, A[2*pivot - mid]);
		else
			pal = 0;

		while (s[mid - pal] == s[mid + pal]){
			pal++;
			if (mid - pal < 0 || mid + pal >= s.size())
				break;
		}
		pal--;
		A[mid] = pal;

		// 03. update the pivot & range values
		if (max_range < pal + mid){
			max_range = pal + mid;
			pivot = mid;
		}
	}
	string max_pal = "";
	for (int i=0; i < s.size(); i++){
		if (max_pal.size() < A[i]*2 + 1)
			max_pal = s.substr(i - A[i], A[i]*2 + 1);
	}
	return max_pal;
}

int main()
{
	cout << getMaxPalOdd("banana") << endl;
	return 0;
}
