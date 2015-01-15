#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    int len = s1.length();
    vector<int> vecch(26,0);
    for (int i = 0; i < len; ++i){ ++vecch[s1[i] - 'a']; --vecch[s2[i] - 'a']; }
    for (int i = 0; i < 26; ++i) if (vecch[i] != 0) return false;
    vector<vector<vector<bool> > > dp(len, vector<vector<bool> >(len, vector<bool>(len+1, false)));
    for (int k = 1; k <= len; ++k)
    {
      for (int i = 0; i <= len - k; ++i)
      {
        for (int j = 0; j <= len - k; ++j)
        {
          if (k == 1)
            dp[i][j][k] = s1[i] == s2[j];
          else
          {
            for (int t = 1; t < k; ++t)
            {
              if (dp[i][j][t] && dp[i + t][j + t][k - t] || dp[i][j + k - t][t] && dp[i + t][j][k - t]){ dp[i][j][k] = true; break; }
            }
          }
        }
      }
    }
    return dp[0][0][len];
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