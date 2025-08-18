class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();

        for(int i = 0; i < mat.size(); i++){
            mat[i].push_back(i);
        }

        sort(mat.begin(), mat.end());
        vector<int> result(k);

        for(int i = 0; i < k; i++){
            result[i] = mat[i][m];
        }
        return result;
    }
};