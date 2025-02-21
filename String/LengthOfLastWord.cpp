class Solution {
    public:
        int lengthOfLastWord(string s) {
    
            vector <string> tokens;
            stringstream stream(s);
            string intermediate;
            
            while(getline(stream, intermediate, ' '))
            {
                if(intermediate.size()!=0) tokens.push_back(intermediate);
            }
    
            return tokens.back().size();
    
        }
    };