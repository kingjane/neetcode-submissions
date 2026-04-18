class PrefixTree {
private:
    vector<PrefixTree*> child;
    bool isEnd;
    PrefixTree* searchPrefix(string pre) {
        PrefixTree* node = this;
        for (char ch : pre) {
            ch -= 'a';
            if (!node->child[ch]) {
                return nullptr;
            }
            node = node->child[ch];
        }
        return node;
    }
public:
    PrefixTree() : child(26), isEnd(false) {
        
    }
    
    void insert(string word) {
        PrefixTree* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->child[ch]) {
                node->child[ch] = new PrefixTree();
            }
            node = node->child[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* node = this->searchPrefix(word);
        return (node && node->isEnd);
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
