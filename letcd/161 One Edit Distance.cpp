/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length(), len2 = word2.length(),prev,cur;
    vector<int> dp(len2+1,0);
    for (int i = 1; i <= len2; ++i)
      dp[i] = i;
    for (int i = 1; i <= len1; ++i)
    {
      prev = i;
      for (int j = 1; j <= len2; ++j)
      {
        if (word1[i - 1] == word2[j - 1])
          cur = dp[j - 1];  //equal
        else
          cur = min(min(dp[j - 1], prev), dp[j]) + 1;  //dp[j-1]-->replace  dp[j]-->delete  prev-->add
        dp[j - 1] = prev;
        prev = cur;
      }
      dp[len2] = prev;
    }
    return dp[len2];
  }
};

int main()
{
  Solution slu;
  string input = "abc", target = "abe";
  int res = slu.minDistance(input, target);
  cout << res << endl;
  system("pause");
  return 0;
}