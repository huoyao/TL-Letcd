#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for (int k = 2; k <= n; ++k)
      for (int t = 1; t <= k; ++t)
        dp[k] += dp[t - 1] * dp[k-t];
    return dp[n];
  }
};

int main()
{
  Solution slu;
  int input = 3;
  int res = slu.numTrees(input);
  cout << res<<endl;
  system("pause");
}
#endif
