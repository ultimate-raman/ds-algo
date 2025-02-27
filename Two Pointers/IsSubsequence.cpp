class Solution {
    public:
        bool isSubsequence(string s, string t) {
            if(s.size()>t.size()) return false;
            int i=0;
            int j=0;
    
            while(i<s.size() && j <t.size()) {
                while(j<t.size() && s[i] != t[j]) {
                    j++;
                }
    
                if(s[i]==t[j]) {
                    i++;
                    j++;
                }
            }
    
            return i==s.size();
        }
    };