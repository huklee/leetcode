class Solution {
	private static final HashMap<Character, String> keyMap = new HashMap<>();
	
	static{
		keyMap.put('1', "");
		keyMap.put('2', "abc");
		keyMap.put('3', "def");
		keyMap.put('4', "ghi");
		keyMap.put('5', "jkl");
		keyMap.put('6', "mno");
		keyMap.put('7', "pqrs");
		keyMap.put('8', "tuv");
		keyMap.put('9', "wxyz");
	}

	// Backtracking solution
	public List<String> letterCombinations(String digits){
		// Edge case
		if (digits.equals(""))
			return new ArrayList<>();

		List<String> result = new ArrayList<>();
		StringBuilder sb = new StringBuilder();
		backtrack(digits, result, 0, sb);
		return result;
	}

	public void backtrack(String digits, List<String> result, int index, StringBuilder sb){
		// base case
		if (index == digits.length() && !sb.toString().equals("")){
			result.add(sb.toString());
			return;
		}

		assert keyMap.containsKey(digits.charAt(index));
		for (char c: keyMap.get(digits.charAt(index)).toCharArray()){
			sb.append(c);
			backtrack(digits, result, index + 1, sb);
			sb.deleteCharAt(sb.length() - 1);
		}
	}

	// Solution with dummy List of String
	public List<String> letterCombinationsUsingArray(String digits) {
		// Edge case
		if (digits.equals(""))
			return new ArrayList<>();

		List<String> result = new ArrayList<>();
		result.add("");

		for (char digit : digits.toCharArray()) {
			assert keyMap.containsKey(digit);

			List<String> temp = new ArrayList<>();
			for (String s : result) {
				for (char letter : keyMap.get(digit).toCharArray()) {
					temp.add(s + letter);
				}
			}
			result = temp;
		}	   
		return result;
	}
}
