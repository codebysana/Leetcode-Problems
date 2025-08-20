class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> freq;
        int maxCount = 0, n = words.size();

        for(int i = 0; i < n; i++){
            maxCount = max(maxCount , ++freq[words[i]]);
        }

        vector<vector<string>> buckets(maxCount + 1);

        for (const auto& [word, f] : freq){
            buckets[f].push_back(word);
        }

        vector<string> ans;
        for (int i = maxCount; i && ans.size() < k; i--) {
            if (buckets[i].empty()) continue;
            sort(buckets[i].begin(), buckets[i].end());
            for (int j = 0, m = buckets[i].size(); j < m; ++j) {
                ans.push_back(buckets[i][j]);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};