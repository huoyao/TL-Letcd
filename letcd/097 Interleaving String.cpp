#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if (len1 + len2 != len3) return false;
    vector<vector<bool> > res(len1 + 1, vector<bool>(len2 + 1, false));
    res[0][0] = true;
    for (int i = 1; i <= len1; ++i)
      if (s1[i-1] == s3[i-1]) res[i][0] = true;
      else break;
    for (int i = 1; i <= len2; ++i)
      if (s2[i-1] == s3[i-1]) res[0][i] = true;
      else break;
    for (int i = 1; i <= len1; ++i)
    {
      for (int j = 1; j <= len2; ++j)
      {
        int k = i + j;
        if (s1[i - 1] == s3[k - 1]) res[i][j] = res[i - 1][j] || res[i][j];
        if (s2[j - 1] == s3[k - 1]) res[i][j] = res[i][j-1] || res[i][j];
      }
    }
    return res[len1][len2];
  }
};

int main()
{
  Solution slu;
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  bool res = slu.isInterleave(s1, s2, s3);
  cout << res << endl;
  system("pause");
}