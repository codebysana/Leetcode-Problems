class Solution {
public:
    int findMax(vector<int>& piles){
        int maxVal = INT_MIN;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, piles[i]);
        } 
        return maxVal;
    }
    long long calculateHours(vector<int>& piles, int hours){
        long long totalHours = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            totalHours += ceil((double)piles[i] / (double)hours);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = findMax(piles);

        while(left <= right){
            int mid = left + (right - left) / 2;
            long long totalHours = calculateHours(piles, mid);
            if(totalHours <= h){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};