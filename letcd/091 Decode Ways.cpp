#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    if (len == 0) return 0;
    if (s[0] == '0') return 0;
    vector<int> dp(len, 0);
    dp[0] = 1;
    if (len > 1)
    {
      dp[1] += s[1] != '0' ? 1 : 0;
      dp[1] += s.substr(0, 2) >= "10" && s.substr(0, 2) <= "26" ? 1 : 0;
    }
    for (int i = 2; i < len; ++i)
    {
      dp[i] += s[i] != '0' ? dp[i - 1] : 0;
      string tmp(s, i - 1, 2);
      dp[i] += tmp >= "10" && tmp <= "26" ? dp[i - 2] : 0;
    }
    return dp[len - 1];
  }
};

int main()
{
  Solution slu;
  string input = "1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
  int res = slu.numDecodings(input);
  cout << res << endl;
  system("pause");
}
#endif
