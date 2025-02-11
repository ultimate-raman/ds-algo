class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
            int m = matrix.size(), n = matrix[0].size();
            int count = m * n;
            int rotation = 0;
    
            int i = 0, j = 0;
            
            while (count > 0) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 1000; 
                count--;
    
                int nextX = i + directions[rotation].first;
                int nextY = j + directions[rotation].second;
    
                if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && matrix[nextX][nextY] != 1000) {
                    i = nextX;
                    j = nextY;
                } else {
                    rotation = (rotation + 1) % 4;
                    i += directions[rotation].first;
                    j += directions[rotation].second;
                }
            }
    
            return ans;
        }
    };

    
//optimized
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int m = matrix.size();
            int n = matrix[0].size();
    
            int top = 0;
            int bottom = m-1;
            int left = 0;
            int right = n-1;
    
            while(top<=bottom && left<=right) {
                for(int i = left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
    
                for(int i = top; i<=bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
    
                if (top <= bottom) {
                    for (int i = right; i >= left; --i) {
                        ans.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                
                if (left <= right) {
                    for (int i = bottom; i >= top; --i) {
                        ans.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
    
            return ans;
        }
    };