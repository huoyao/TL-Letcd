#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<int, int> mapidx;
    int win=0, len = s.length(),idx=0;
    while (idx < 9)
      win = win << 3 | s[idx++] & 7;
    while (idx<len)
      if (mapidx[win = win << 3 & 0x3FFFFFFF | s[idx++] & 7]++ == 1)
        res.push_back(s.substr(idx-10,10));
    return res;
  }
};

int main()
{
  Solution slu;
  string ss = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> res = slu.findRepeatedDnaSequences(ss);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}
#endif
