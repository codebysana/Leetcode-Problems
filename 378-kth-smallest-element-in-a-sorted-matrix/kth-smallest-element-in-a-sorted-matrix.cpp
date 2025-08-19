class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        priority_queue<int> maxHeap;

        for(int row = 0; row < m; row++){
            for(int cols = 0; cols < n; cols++){
                maxHeap.push(matrix[row][cols]);

                if(maxHeap.size() > k){
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();
    }
};