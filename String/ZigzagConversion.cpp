class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1) return s;
            string ans;
            vector<string> concat(numRows);
    
            int curr = 0;
            int appender = -1;
    
            for(char c: s) {
                concat[curr] += c;
                if(curr==0 || curr==numRows-1) appender = appender*-1;
                curr+=appender;
            }
    
            for(string s: concat) {
                ans +=s;
            }
    
            return ans;
        }
    };