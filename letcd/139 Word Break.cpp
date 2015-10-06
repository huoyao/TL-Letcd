#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty() || dict.empty()) return false;
    vector<bool> dp(s.length()+1,false);
    dp[0] = true;
    for (int i = 0; i < s.length(); ++i)
    {
      if (dp[i])
      {
        for (int len = 1; len + i - 1 < s.length(); ++len)
        {
          string str = s.substr(i,len);
          if (dict.count(str))
            dp[i + len] = true;
        }
      }
      if (dp[s.length()]) return true;
    }
    return dp[s.length()];
  }
};

int main()
{
  Solution slu;
  string s = "leetcoe";
  unordered_set<string> dict = {"leet","code","det"};
  bool res = slu.wordBreak(s, dict);
  cout << res<<endl;
  system("pause");
}
#endif
