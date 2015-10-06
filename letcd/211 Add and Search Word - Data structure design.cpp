#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tie
{
  bool is_end;
  Tie *child[26];
  Tie():is_end(false){
    for(size_t i = 0;i < 26;++i) child[i] = NULL;
  }
};

class WordDictionary
{
public:
  WordDictionary()
  {
    root = new Tie();
  }
  // Adds a word into the data structure.
  void addWord(string word) {
    Tie *ptr = root;
    for(size_t i = 0;i < word.length();++i)
    {
      int id = word[i] - 'a';
      if(ptr->child[id] == NULL)
      {
        ptr->child[id] = new Tie();
        ptr = ptr->child[id];
      } else
      {
        ptr = ptr->child[id];
      }
    }
    ptr->is_end = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return find(word, root);
  }

  bool find(string key,Tie *ptr)
  {
    if(key.length() == 0) return ptr&&ptr->is_end;
    int id = key[0] - 'a';
    if(key[0] == '.')
    {
      for(size_t i = 0;i < 26;++i)
      {
        if(!ptr->child[i]) continue;
        if(key.length() == 1 && ptr->child[i]->is_end) return true;
        if(find(key.substr(1, key.length() - 1), ptr->child[i])) return true;
      }
      return false;
    } else if(ptr->child[id])
    {
      if(key.length() == 1) return ptr->child[id]->is_end;
      else return find(key.substr(1, key.length() - 1), ptr->child[id]);
    }
    return false;
  }
private:
  Tie *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
  WordDictionary slu;
  slu.addWord("good");
  slu.addWord("bad");
  cout<<".ad"<<slu.search(".ad")<<endl;
  cout << "good" << slu.search("good") << endl;
  cout << "goo" << slu.search("goo") << endl;
  cout << endl;
  system("pause");
  return 0;
}
#endif
