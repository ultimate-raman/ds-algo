class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<string, int> mp = {
                {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, 
                {"C", 100}, {"D", 500}, {"M", 1000},
                {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, 
                {"CD", 400}, {"CM", 900}
            };
    
            int sum = 0;
            int n = s.size();
    
            for (int i = 0; i < n; i++) {
                if (i < n - 1 && mp.find(s.substr(i, 2)) != mp.end()) {
                    sum += mp[s.substr(i, 2)];
                    i++;
                } else {
                    sum += mp[string(1, s[i])];
                }
            }
    
            return sum;
        }
    };
    