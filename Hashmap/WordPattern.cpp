class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            vector<string> words;
            stringstream st(s);
            string word;
    
            while (getline(st, word, ' ')) {
                words.push_back(word);
            }
    
            if (pattern.size() != words.size()) return false;
    
            unordered_map<char, string> patternToWord;
            unordered_map<string, char> wordToPattern;
    
            for (int i = 0; i < pattern.size(); i++) {
                if (patternToWord.find(pattern[i]) == patternToWord.end() && wordToPattern.find(words[i]) == wordToPattern.end()) {
                    patternToWord[pattern[i]] = words[i];
                    wordToPattern[words[i]] = pattern[i];
                }
                else if (patternToWord[pattern[i]] != words[i] || wordToPattern[words[i]] != pattern[i]) {
                    return false;
                }
            }
    
            return true;
        }
    };
    