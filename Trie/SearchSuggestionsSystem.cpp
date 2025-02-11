struct Node {
    Node* arr[26];

    vector<string> suggestions;

    Node() {
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
    }

    bool valueExists(char c) {
        return (arr[c-'a'] == NULL) ? false : true;
    }

    void setChar(char c) {
        arr[c-'a'] = new Node();
    }

    Node* getChar(char c) {
        return arr[c-'a'];
    }

    void modifySuggestions(string word) {
        if(suggestions.size()<3) {
            suggestions.push_back(word);
        }
    }

    vector<string> getSuggestions() {
        return suggestions;
    }

};

class Trie {
    private:
    Node* root;

    public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* crawler = root;

        for(char c: word) {
            if(!crawler->valueExists(c)) {
                crawler->setChar(c);
            }
            crawler = crawler->getChar(c);
            crawler->modifySuggestions(word);
        }
    }

    vector<vector<string>> getSuggestions(string word) {
        vector<vector<string>> ans;
        bool prefixStillValid = true;
        Node* crawler = root;

        for (char c : word) {
            if (!prefixStillValid || !crawler->valueExists(c)) {
                ans.push_back({});
                prefixStillValid = false; 
            } else {
                crawler = crawler->getChar(c);
                ans.push_back(crawler->getSuggestions());
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;

        sort(products.begin(),products.end());

        for(string s: products) {
            t.insert(s);
        }

        return t.getSuggestions(searchWord);
    }
};