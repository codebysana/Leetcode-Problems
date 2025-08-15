class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;

        for(int a : answers){
            freq[a]++;
        }

        int count = 0;
        for(const auto& [r, v] : freq){
            int groupSize = r + 1;
            int groups = (r + v) / groupSize;
            count += groups * groupSize;
        }
        return count;
    }
};