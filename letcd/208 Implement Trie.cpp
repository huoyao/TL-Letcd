#if 0
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
  char c;
  bool is_end;
  int num_shared;
  vector<TrieNode *> child;
  // Initialize your data structure here.
  TrieNode():c(' '), is_end(false), num_shared(0) {}
  TrieNode(const char &ch):c(ch), is_end(false), num_shared(0){}
  ~TrieNode()
  {
    for(size_t i = 0;i < child.size();++i) delete child[i];
  }
  TrieNode * findNext(const char &ch)
  {
    for(size_t i = 0;i < child.size();++i)
    {
      if(child[i]->c == ch) return child[i];
    }
    return NULL;
  }
};

class Trie
{
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    if(search(s)) return;
    TrieNode *curr = root;
    for(size_t i = 0;i < s.length();++i)
    {
      TrieNode *child = curr->findNext(s[i]);
      if(child != NULL)
      {
        curr = child;
        ++curr->num_shared;
      } else
      {
        TrieNode *new_node = new TrieNode(s[i]);
        curr->child.push_back(new_node);
        ++curr->num_shared;
        curr = new_node;
      }
    }
    curr->is_end = true;
  }

  // Returns if the word is in the trie.
  bool search(string key) {
    TrieNode *curr = root;
    for(size_t i = 0;i < key.size();++i)
    {
      curr = curr->findNext(key[i]);
      if(curr == NULL) return false;
    }
    return curr->is_end;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *curr = root;
    for(size_t i = 0;i < prefix.size();++i)
    {
      curr = curr->findNext(prefix[i]);
      if(curr == NULL) return false;
    }
    return true;
  }

private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
  Trie tire;
  tire.insert("good");
  cout << tire.search("good");
  cout << tire.search("bad");
  return 0;
}
#endif
