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
    vector<int> dp(tlen+1,0);
      dp[0] = 1;
    for (int i = 1; i <= slen; ++i)
      for (int j = tlen; j >= 1; --j)
        dp[j] += S[i - 1] == T[j - 1] ? dp[j - 1] : 0;
    return dp[tlen];
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