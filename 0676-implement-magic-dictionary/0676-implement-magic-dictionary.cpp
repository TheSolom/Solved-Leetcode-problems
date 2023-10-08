class trie
{
    private:
        static
    const int MAX_CHAR = 26;
    trie *child[MAX_CHAR] {};
    bool isLeaf {};

    public:
        void insert(string str)
        {
            trie *cur = this;

            for (int i = 0; i < (int) str.size(); i++)
            {
                int idx = str[i] - 'a';
                if (!cur->child[idx])
                    cur->child[idx] = new trie();

                cur = cur->child[idx];
            }
            cur->isLeaf = true;
        }

    bool word_exist(string str)
    {
       	// If recursive: Time Limit Exceeded on leetcode
        trie *cur = this;

        for (int idx = 0; idx < (int) str.size(); ++idx)
        {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                return false;

            cur = cur->child[ch];
        }
        return cur->isLeaf;
    }

    bool word_exist_with_1_change(string str)
    {
       	// Brute force all possible 1-char change and search for it O(L *26 *L)
        for (int i = 0; i < (int) str.size(); i++)
        {
            char cpy = str[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != cpy)
                {
                    str[i] = ch;
                    if (word_exist(str))
                        return true;
                }
            }
            str[i] = cpy;	// copy back
        }
        return false;
    }
};

class MagicDictionary
{
    public:
        trie tree;

    MagicDictionary() {}

    void buildDict(vector<string> dictionary)
    {
        for (int i = 0; i < (int) dictionary.size(); i++)
            tree.insert(dictionary[i]);
    }

    bool search(string searchWord)
    {
        return tree.word_exist_with_1_change(searchWord);
    }
};

/**
 *Your MagicDictionary object will be instantiated and called as such:
 *MagicDictionary* obj = new MagicDictionary();
 *obj->buildDict(dictionary);
 *bool param_2 = obj->search(searchWord);
 */