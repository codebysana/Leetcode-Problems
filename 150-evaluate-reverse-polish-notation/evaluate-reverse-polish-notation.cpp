class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string i : tokens){
            if(i == "+"){
                int plusA = st.top(); st.pop();
                int plusB = st.top(); st.pop();
                st.push(plusB + plusA);
            }else if(i == "-"){
                int minusA = st.top(); st.pop();
                int minusB = st.top(); st.pop();
                st.push(minusB - minusA);
            }
           else if(i == "*"){
                int mulA = st.top(); st.pop();
                int mulB = st.top(); st.pop();
                st.push(mulB * mulA);
            }
            else if(i == "/"){
                int divA = st.top(); st.pop();
                int divB = st.top(); st.pop();
                st.push(divB / divA);
            }else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};