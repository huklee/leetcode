class Solution {
	public String longestCommonPrefix(String[] strs){
		int maxStrLen = 0;
		int minLen = Arrays.stream(strs).mapToInt(x -> x.length()).min().getAsInt();
		for (int i =0 ; i < minLen ; i++){
			char c = strs[0].charAt(i);
			boolean isAllSame = true;
			for (int j =0; j < strs.length; j++){
				if (strs[j].charAt(i) != c)
					isAllSame = false;
			}
			maxStrLen = isAllSame ? maxStrLen + 1 : maxStrLen;
			if (!isAllSame)
				break;
		}
		return strs[0].substring(0, maxStrLen);
	}
}
