class Trie {
public:
    vector<string> trie;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        trie.push_back(word);
        
    }
    
    bool search(string word) {
        return (find(trie.begin(),trie.end(),word))!=trie.end();
        
    }
    
    bool startsWith(string prefix) {
        for(int i=0; i<trie.size();i++){
            if(trie[i].size()<prefix.size()) continue;
            else if(trie[i].substr(0,prefix.size())==prefix) return true;
        }
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */