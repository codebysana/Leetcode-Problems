class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> positions;
        for (int i = 0; i < n; i++) {
            positions.push(i);
        }

        vector<int> result(n, 0);
        int cardIndex = 0;

        while(!positions.empty()){
            int pos = positions.front();

            positions.pop();
            result[pos] = deck[cardIndex++];

            if(!positions.empty()){
                int nextPos = positions.front();
                positions.pop();
                positions.push(nextPos);
            }
        }
        return result;
    }
};