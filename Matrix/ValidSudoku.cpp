class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
    
            unordered_set<string> st;
    
            for(int i=0; i<board.size();i++) {
                for(int j=0; j<board[0].size(); j++) {
                    if(board[i][j] == '.') continue;
    
                    string row = "ROW_" + to_string(i) + "_" + board[i][j];
                    string column = "COLUMN_" + to_string(j) + "_" + board[i][j];
                    string box = "BOX_" + to_string(i / 3) + "_" + to_string(j / 3) + "_" + board[i][j];
    
                    if(st.find(row) != st.end() || st.find(column) != st.end() || st.find(box) != st.end()) return false;
    
                    st.insert(row);
                    st.insert(column);
                    st.insert(box);
                }
            }
    
    
            return true;
        }
    };