class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.size()==0) return 0;
            unordered_set<char> st;
            int back = 0;
            int ans = INT_MIN;
    
            for(int i=0; i<s.size();i++) {
    
                if(st.find(s[i]) != st.end()){
                    while(s[back]!=s[i]) {
                        st.erase(s[back]);
                        back++;
                    }
                    back++;
                }
    
                else {
                    st.insert(s[i]);
                }
    
                ans = max(ans,i+1-back);
            }
    
            return ans;
        }
    };