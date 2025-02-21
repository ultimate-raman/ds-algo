class Solution {
    public:
        string reverseWords(string s) {
            string ans;
    
            stringstream stream(s);
            string intermediate;
    
            while(getline(stream,intermediate,' ')){
                if(intermediate == "") continue;
                ans = intermediate + ans;
                ans=" "+ans;
            }
    
            ans=ans.substr(1,ans.size()-1);
    
            return ans;
        }
    };