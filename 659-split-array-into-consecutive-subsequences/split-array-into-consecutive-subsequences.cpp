class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, seq;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            left[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(!left[nums[i]]) continue;

            if(seq[nums[i] - 1]){
                left[nums[i]]--;
                seq[nums[i] - 1]--;
                seq[nums[i]]++;
            }
            else{
                if(!left[nums[i] + 2] || !left[nums[i] + 1]){
                    return false;
                }
                left[nums[i]]--;
                left[nums[i] + 1]--;
                left[nums[i] + 2]--;
                seq[nums[i] + 2]++;
            }
        }
        return true;
    }
};