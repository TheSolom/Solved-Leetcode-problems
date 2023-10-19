#include<iostream>
#include<vector>
#include<set>
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 27;
	trie* child[MAX_CHAR]{};
	int index {-1};		// If exist, don't override

public:
	void insert(const string &str, int word_idx) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); idx++) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();

			if(cur->child[ch]->index == -1)
				cur->child[ch]->index = word_idx;

			cur = cur->child[ch];
		}
	}

	int get_positions(const string& str) {
	    trie* cur = this;

	    for (int idx = 0; idx < (int)str.size(); idx++) {
		    int ch = str[idx] - 'a';
		    if (!cur->child[ch])
			    return -1;

		    cur = cur->child[ch];
	    }
	    return cur->index;
    }
};

class WordFilter {
public:
	trie tree;

	WordFilter(vector<string>& words) {
		set<string> words_set;

		// Generate all pairs of suffix/prefix
		// But, trie already generate all prefixes, so generate suffixes + one prefix
		// Use unique symbol to differentiate suffix from prefix (otherwise a word is unclear)
		// As we create more words (n^2), this solution needs more memory
		// But it queries in faster time!
		for (int i = (int)words.size() - 1; i >= 0; i--) {
			if (words_set.insert(words[i]).second) {

				string suffix;
				for (int j = (int)words[i].size() - 1; j >= 0; j--) {
					suffix = words[i][j] + suffix;
					string new_word = suffix + "{" + words[i];
					tree.insert(new_word, i);
				}
			}
		}
	}

	int f(string prefix, string suffix) {
		string new_word = suffix + "{" + prefix;
		return tree.get_positions(new_word);
	}
};

