import java.util.Stack;

public class Solution {
	boolean isOperator(String s) {
		return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
	}

	int eval(String op, int n1, int n2) {
		switch (op) {
			case "+":   return n1 + n2;
			case "-":   return n1 - n2;
			case "*":   return n1 * n2;
			case "/":   return n1 / n2; 
			default:	throw new IllegalArgumentException("Invalid operator");
		}
	}

	public int evalRPN(String[] tokens) {
		Stack<Integer> stack = new Stack<>();
		
		for (String s : tokens) {
			if (isOperator(s)) {
				if (stack.size() < 2)
					throw new IllegalArgumentException("Invalid RPN expression");

				int n2 = stack.pop();
				int n1 = stack.pop();
				stack.push(eval(s, n1, n2));
			} else {
				stack.push(Integer.parseInt(s));
			}
		}
		
		if (stack.size() != 1)
			throw new IllegalArgumentException("Invalid RPN expression");

		return stack.pop();
	}
}
