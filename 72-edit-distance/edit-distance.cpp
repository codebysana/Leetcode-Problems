class Solution {
private:
    int helper(const string& word1, const string& word2, int i, int j, vector<vector<int>>& seen) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (seen[i][j] != -1) return seen[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            seen[i][j] = helper(word1, word2, i - 1, j - 1, seen);
        } else {
            seen[i][j] = 1 + min({
                helper(word1, word2, i - 1, j, seen),     
                helper(word1, word2, i, j - 1, seen),     
                helper(word1, word2, i - 1, j - 1, seen)  
            });
        }

        return seen[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> seen(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, seen);
    }
};