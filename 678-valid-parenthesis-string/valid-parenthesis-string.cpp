class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; 
        int high = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(ch == '('){
                low++;
                high++;
            }else if(ch == ')'){
                low--;
                high--;
            }else if(ch == '*'){
                low--;
                high++;
            }

            if(high < 0){
                return false;
            }

            low  = max(low, 0);
        }
        return low == 0;
    }
};