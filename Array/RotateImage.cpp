class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int i = 0;
            int n = matrix.size();
    
            while(i<n) {
                int j = i;
                while(j<n) {
                    swap(matrix[i][j],matrix[j][i]);
                    j++;
                }
                i++;
            }
            i = 0;
    
            while(i<n) {
                int j = 0;
                while(j<n/2) {
                    swap(matrix[i][j],matrix[i][n-1-j]);
                    j++;
                }
                i++;
            }
    
    
        }
    };