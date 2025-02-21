class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = strs[0];
    
            for(int i=1; i<strs.size(); i++) {
                if(ans.size()==0) return "";
    
                int j = 0;
                while(j<strs[i].size()) {
                    if(ans[j] == strs[i][j]){
                        j++;
                    }
                    else {
                        break;
                    }
                }
    
                ans = ans.substr(0,j);
            }
    
            return ans;
        }
    };