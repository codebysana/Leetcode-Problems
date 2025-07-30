class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        int idx = 0;

        while(idx < s.size()){
            if(temp.empty() || s[idx] != temp.back()){
                temp.push_back(s[idx]);
            }else{
                temp.pop_back();
            }
            idx++;
        }
        return temp;
    }
};