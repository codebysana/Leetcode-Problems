class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0;
        int maxLen = 0;
        int zeroCount = -1;

        for(int end = 0; end < nums.size(); end++){
            if(nums[end] == 0){
                start = zeroCount + 1;
                zeroCount = end;
            }
            maxLen = max(maxLen, end - start);
        }
        return maxLen;
    }
};