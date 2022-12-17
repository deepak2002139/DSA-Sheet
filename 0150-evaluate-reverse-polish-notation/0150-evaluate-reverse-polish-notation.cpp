class Solution {
public:
       int isSign(string s) {
        vector<string> sign = {"+","-","*","/"};
        for(int i = 0; i < sign.size(); i++) {
            if(sign[i] == s) return i;
        }

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i = 0; i < n; i++) {
            int sign = isSign(tokens[i]);

            if(sign == -1) {
                int x = stoi(tokens[i]);
                st.push(x);
            }
            else {
                if(st.empty()) continue;

                int b = st.top();st.pop();
                int a = st.top();st.pop();

                if(sign == 0) st.push(a+b);
                else if(sign == 1) st.push(a-b);
                else if(sign == 2) st.push(1LL*a*b);
                else st.push(a/b);
            }
        }

        return (st.empty()) ? -1 : st.top(); 
    }
};