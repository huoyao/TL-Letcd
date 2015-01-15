#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    if (s1 == s2) return true;
    int len = s1.length();
    vector<int> vecch(26,0);
    for (int i = 0; i < len; ++i){ ++vecch[s1[i] - 'a']; --vecch[s2[i] - 'a']; }
    for (int i = 0; i < 26; ++i) if (vecch[i] != 0) return false;
    bool res = false;
    for (int t = 1; t < len; ++t)
    {
      res = isScramble(s1.substr(0, t), s2.substr(0, t)) && isScramble(s1.substr(t),s2.substr(t));
      if (res) return res;
      res = isScramble(s1.substr(0, t), s2.substr(len - t)) && isScramble(s1.substr(t), s2.substr(0, len-t));
      if (res) return res;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  string input = "abc",target="bca";
  bool res = slu.isScramble(input, target);
  cout << res<<endl;
  system("pause");
}