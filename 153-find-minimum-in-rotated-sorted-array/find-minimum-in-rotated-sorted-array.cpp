class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = INT_MAX;
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < minVal){
                minVal = nums[mid];
            }
            if(nums[left] <= nums[mid]){
                minVal = min(nums[left], minVal);
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return minVal;
    }
};