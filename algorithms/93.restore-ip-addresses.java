import java.util.ArrayList;
import java.util.List;

class Solution {
	public List<String> restoreIpAddresses(String s) {
		List<String> result = new ArrayList<>();
		int n = s.length();
		
		for (int i = 1; i <= 3 && i < n; i++) {
			for (int j = i + 1; j <= i + 3 && j < n; j++) {
				for (int k = j + 1; k <= j + 3 && k < n; k++) {
					String first = s.substring(0, i);
					String second = s.substring(i, j);
					String third = s.substring(j, k);
					String fourth = s.substring(k);

					if (n - k <= 3 
							&& isValidSegment(first)
							&& isValidSegment(second)
							&& isValidSegment(third) 
							&& isValidSegment(fourth)) {
						result.add(first + "." + second + "." + third + "." + fourth);
					}
				}
			}
		}
		return result;
	}

	private boolean isValidSegment(String segment) {
		if (segment.length() > 1 && segment.charAt(0) == '0') return false;
		int num = Integer.parseInt(segment);
		return num >= 0 && num < 256;
	}

	// Recursive implementation
	private void backtrack(String s, int start, List<String> result, String cur, int numSegments){
		if (numSegments == 4 && start == s.length()){
			result.add(cur);
			return;
		}

		for (int i = start; i < Math.min(start + 3, s.length()); i++){
			String segment = s.substring(start, i + 1);
			if (isValidSegment (segment)){
				String newCur = cur.isEmpty() ? segment : cur + "." + segment;
				backtrack(s, i + 1, result, newCur, numSegments + 1);
			}
		}
	}
}
