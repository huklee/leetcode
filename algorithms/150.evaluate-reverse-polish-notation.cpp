class Solution {
public:
    bool isOperator(string s){
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int eval(string op, int n1, int n2){
        if (op == "+")      return n1 + n2;
        else if (op == "-") return n1 - n2;
        else if (op == "*") return n1*n2;
        else{
            assert (op == "/");
            return n1 / n2;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        st.push(0);
        for (string s : tokens){
            if (isOperator(s)){
                assert(st.size() > 1);
                int n2 = st.top();  st.pop();
                int n1 = st.top();  st.pop();
                st.push(eval(s,n1,n2));
            }
            else
                st.push(stoi(s));
        }
        assert(st.size() > 0);
        return st.top();
    }
};
