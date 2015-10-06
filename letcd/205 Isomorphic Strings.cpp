#if 0
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t) {
    int len = s.length();
    if(len != t.length()) return false;
    unordered_set<int> all_inc;
    int tag[256];
    for(size_t i = 0;i < 256;++i) tag[i] = -1;
    for(size_t i = 0;i < len;++i)
    {
      if(tag[s[i]] == -1)
      {
        if(all_inc.count(t[i])) return false;
        tag[s[i]] = t[i];
        all_inc.insert(t[i]);
      }
      else if(tag[s[i]] != t[i]) return false;
    }
    //int mine = 0;
    //for(size_t i = 0;i < 256;++i)
    //{
    //  if(tag[i] != -1 && tag[i] <= mine) return false;
    //  else if(tag[i]!=-1) mine = tag[i];
    //}
    return true;
  }
};

int main()
{
  Solution slu;
  string input = "ab";
  string target = "ca";
  bool res = slu.isIsomorphic(input, target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
