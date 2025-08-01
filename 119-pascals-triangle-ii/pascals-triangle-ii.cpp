class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal(rowIndex, 1);

        for(int i = 0; i < rowIndex + 1; i++){
            vector<int> row(i + 1, 1);

            for(int j = 1; j < i; j++){
                row[j] = pascal[j - 1] + pascal[j];
            }
            pascal = row;
        }
        return pascal;
    }
};