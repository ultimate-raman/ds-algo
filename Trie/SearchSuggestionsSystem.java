package Trie;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SearchSuggestionsSystem {
    private class TrieNode {
        TrieNode[] trieArray = new TrieNode[26];
        boolean isEnd = false;
        List<String> mapping = new ArrayList<>();
    }

    private final TrieNode root = new TrieNode();
    
    public void insert(String word) {
        TrieNode node = root;
        for(char c: word.toCharArray()) {
            if(node.trieArray[c-'a'] == null) {
                node.trieArray[c-'a'] = new TrieNode();
            }
            node = node.trieArray[c-'a'];

            if(node.mapping.size() < 3) node.mapping.add(word);
        }
        node.isEnd = true;
    }

    public List<List<String>> searchSuggestions(String searchWord) {
        List<List<String>> ans = new ArrayList<>();

        TrieNode node = root;

        boolean noMatch = false;

        for(char c: searchWord.toCharArray()) {
            if(noMatch || node.trieArray[c-'a'] == null) {
                ans.add(new ArrayList<>());
                noMatch = true;
            }
            else {
                node = node.trieArray[c-'a'];
                ans.add(node.mapping);
            }

        }
        
        return ans;
    }
    

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        TrieNode trie = new TrieNode();

        Arrays.sort(products);

        for(String product: products) {
            this.insert(product);
        }

        
        return searchSuggestions(searchWord);
    }
}
