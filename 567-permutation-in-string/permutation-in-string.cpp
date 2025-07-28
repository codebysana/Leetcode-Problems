class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        for(int i = 0; i < s1.length(); i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }

        if(count1 == count2){
            return true;
        }

        int st = 0;
        for(int end = s1.length(); end < s2.length(); end++){
            count2[s2[end]]++;
            count2[s2[st]]--;

        if(count2[s2[st]] == 0){
             count2.erase(s2[st]);
        }
        st++;

        if(count1 == count2){
            return true;
        }
    }
    return false;
    }
};