#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    int slen = strlen(s), plen = strlen(p);
    vector<vector<bool> > matched_dp(slen + 1, vector<bool>(plen + 1));
    matched_dp[0][0]=true;
    for (int i = 1; i <= slen; ++i) matched_dp[i][0] = false;
    for (int i = 0; i < plen; ++i) matched_dp[0][i+1] = i > 0 && p[i] == '*' &&matched_dp[0][i - 1];
    for (int i = 0; i < slen; ++i)
    {
      for (int j = 0; j < plen; ++j)
      {
        if (p[j] != '*') matched_dp[i + 1][j + 1] = matched_dp[i][j] && (p[j] == '.' || s[i] == p[j]);
        else matched_dp[i + 1][j + 1] = matched_dp[i + 1][j - 1] && j>0 ||
          matched_dp[i + 1][j] || matched_dp[i][j + 1] && j>0 && (p[j - 1] == '.' || p[j - 1] == s[i]);
      }
    }
    return matched_dp[slen][plen];
  }
};

int main()
{
  Solution slu;
  char s[] = "aa", p[] = "aa";
  bool res = slu.isMatch(s, p);
  cout << res << endl;
  system("pause");
}