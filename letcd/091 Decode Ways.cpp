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
    vector<int> dp(len, 0);
    for (int i = 0; i < len; ++i)
    {
      if (s[i] >= '1' && s[i] <= '9')
      {
        if (i == 0) dp[i] = 1;
        else dp[i] += dp[i - 1];
      }
      if (i == 0) continue;
      string tmp(s, i - 1, 2);
      if (tmp >= "10" && tmp <= "26")
      {
        if (i > 1) dp[i] += dp[i - 2];
        else dp[i] += 1;
      }
    }
    return dp[len-1];
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