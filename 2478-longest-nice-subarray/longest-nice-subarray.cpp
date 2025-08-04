class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;
        int start = 0, maxLen = 0;

        for(int end = 0; end < nums.size(); end++){
            while((usedBits & nums[end]) != 0){
                usedBits ^= nums[start];
                start++;
            }
            usedBits |= nums[end];

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};