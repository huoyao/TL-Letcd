#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length(), len2 = word2.length(),pre,cur;
    vector<int> dp(len2+1);
    for (int i = 0; i <= len2; ++i)
      dp[i] = i;
    for (int i = 1; i <= len1; ++i)
    {
      pre = i;
      for (int j = 1; j <= len2; ++j)
      {
        if (word1[i - 1] == word2[j - 1]) cur= dp[j-1];
        else cur=min(pre,min(dp[j],dp[j-1]))+1;
        dp[j - 1] = pre;
        pre = cur;
      }
      dp[len2] = pre;
    }
    return dp[len2];
  }
};

int main()
{
  Solution slu;
  string input = "abcd",target = "dc";
  int res = slu.minDistance(input, target);
  cout << res<<endl;
  system("pause");
}