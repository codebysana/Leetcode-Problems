class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> seen;

        for(int num : nums){
            if(seen.find(num) == seen.end()){
                seen.insert(num);
                minHeap.push(num);

                if(minHeap.size() > 3){
                    minHeap.pop();
                }
            }
        }
        if(minHeap.size() < 3){
            int maxVal = minHeap.top();
            
            while(!minHeap.empty()){
                maxVal = max(maxVal, minHeap.top());
                minHeap.pop();
            }
            return maxVal;
        }
        return minHeap.top();
    }
};