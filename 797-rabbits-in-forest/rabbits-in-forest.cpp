class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;

        for(int a : answers){
            freq[a]++;
        }

        int count = 0;
        for(auto& [num, k] : freq){
            int groupSize = num + 1;
            int groups = (num + k) / groupSize;
            count += groups * groupSize;
        }
        return count;
    }
};