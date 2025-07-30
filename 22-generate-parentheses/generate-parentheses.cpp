class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<string, int, int>> st;

        st.push({"", n, n});

        while(!st.empty()){
            auto [current, open, close] = st.top();
            st.pop();

            if(open == 0 && close == 0){
                result.push_back(current);
            }

            if(open > 0){
                st.push({current + "(", open - 1, close});
            }

            if(close > open){
                st.push({current + ")", open, close - 1});
            }
        }
        return result;
    }
};