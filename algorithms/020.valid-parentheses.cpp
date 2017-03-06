class Solution {
public:
    bool is_match(char o, char c){
        if ((o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']'))
            return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        if (s.size() == 0)
            return true;
            
        for (int i=0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (st.empty() || !is_match(st.top(),s[i]))
                return false;
            else
                st.pop();
        }

        // if (st.empty())
        //     return true;
        // else
        //     return false;
		return st.empty();
    }
};
