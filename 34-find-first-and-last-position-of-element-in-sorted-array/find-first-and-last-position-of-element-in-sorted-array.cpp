class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int start = binarySearch(nums, target, true);
        int end = binarySearch(nums, target, false);
        result[0] = start;
        result[1] = end;
        return result;
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchLeft){
        int start = 0, end = nums.size() - 1;
        int index = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else {
                index = mid;
            if(isSearchLeft){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            }
        }
        return index;
    }
};