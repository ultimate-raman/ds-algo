class Solution {
    public:
        bool isPalindrome(string s) {
            string s1;
            for(char c:s){
                if(c>='a'&&c<='z' || c>='0'&&c<='9'){
                    s1+=c;
                }
                else if(c>='A'&&c<='Z'){
                    s1+=c+32;
                }
            }
            int left=0;
            int right=s1.size()-1;
            while(left<right){
                if(s1[left]==s1[right]) {
                    left++;
                    right--;
                } else return false;            
            }
            return true;
        }
    };

