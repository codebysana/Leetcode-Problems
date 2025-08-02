class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s){
        stack<char> st;
        for(char ch : s){
            if(ch != '#'){
                st.push(ch);
            }else if(!st.empty()){
                st.pop();
            }
        }
        // Convert stack to string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};