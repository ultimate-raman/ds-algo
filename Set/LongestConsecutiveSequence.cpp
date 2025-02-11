class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.empty()) return 0;
    
            unordered_set<int> st(nums.begin(), nums.end());
            int ans = 0;
    
            for (int num : st) {
                if (st.find(num - 1) == st.end()) {
                    int count = 1;
                    int temp = num + 1;
    
                    while (st.find(temp) != st.end()) {
                        count++;
                        temp++;
                    }
    
                    ans = max(ans, count);
                }
            }
    
            return ans;
        }
    };
    