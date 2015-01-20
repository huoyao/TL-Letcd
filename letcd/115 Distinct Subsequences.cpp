#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int numDistinct(string S, string T) {
    int slen = S.length(), tlen = T.length();
    if (tlen > slen) return 0;
    vector<vector<int> > dp(slen+1,vector<int>(tlen+1,0));
    for (int i = 0; i <= slen; ++i)
      dp[i][0] = 1;
    for (int i = 1; i <= slen; ++i)
    {
      for (int j = 1; j <= tlen; ++j)
      {
        dp[i][j] = S[i - 1] == T[j - 1] ? dp[i - 1][j - 1] : 0;
        dp[i][j] += i - 1 >= j ? dp[i - 1][j] : 0;
      }
    }
    return dp[slen][tlen];
  }
};

int main()
{
  Solution slu;
  string input = "ccc",target="c";
  int res = slu.numDistinct(input, target);
  cout << res<<endl;
  system("pause");
}