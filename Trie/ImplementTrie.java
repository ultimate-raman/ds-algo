package Trie;

public class ImplementTrie {
    private class TrieNode {
        TrieNode[] trieArray = new TrieNode[26];
        boolean isEnd = false;
    }

    private final TrieNode root = new TrieNode();

    public void Trie() {
        //do nothing
    }
    
    public void insert(String word) {
        TrieNode node = root;
        for(char c: word.toCharArray()) {
            if(node.trieArray[c-'a'] == null) {
                node.trieArray[c-'a'] = new TrieNode();
            }
            node = node.trieArray[c-'a'];
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for(char c: word.toCharArray()) {
            if(node.trieArray[c-'a'] == null) {
                return false;
            }
            node = node.trieArray[c-'a'];
        }

        return node.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for(char c: prefix.toCharArray()) {
            if(node.trieArray[c-'a'] == null) {
                return false;
            }
            node = node.trieArray[c-'a'];
        }

        return true;
    }
}
