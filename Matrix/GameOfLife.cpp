class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            vector<int> dirs = {-1,0,1};
            int m = board.size();
            int n = board[0].size();
    
    
            //0 -> 0
            //1 -> 1
            //1 -> 0 = -2
            //0 -> 1 = 2
    
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
    
                    int live_neighbors = 0;
    
                    for (int di : dirs) {
                        for (int dj : dirs) {
                            if (di == 0 && dj == 0) continue;
                            int ni = i + di, nj = j + dj;
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] == 1 || board[ni][nj] == -2)) {
                                live_neighbors++;
                            }
                        }
                    }
    
                    if (board[i][j] == 1) {
                        if (live_neighbors < 2 || live_neighbors > 3) board[i][j] = -2;
                    } else {
                        if (live_neighbors == 3) board[i][j] = 2;
                    }
    
                }
            }
    
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == -2) board[i][j] = 0;
                    else if (board[i][j] == 2) board[i][j] = 1;
                }
            }
        }
    };