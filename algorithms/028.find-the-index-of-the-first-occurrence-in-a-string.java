class Solution {
	public int strStr(String haystack, String needle) {
		if (needle.length() > haystack.length())
			return -1;

		for (int i = 0; i <= haystack.length() - needle.length(); i++){
			// if (haystack.substring(i,i + needle.length()).equals(needle))
			if (compareSubstring(haystack, needle, i))
				return i;
		}
		return -1;
	}

	private boolean compareSubstring(String a, String b, int point){
		for (int i=0 ; i < b.length(); i++){
			if (a.charAt(point + i) != b.charAt(i))
				return false;
		}
		return true;
	}
}
