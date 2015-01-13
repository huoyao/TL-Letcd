#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length() + 1, len2 = word2.length() + 1;
    vector<vector<int> > vec(len1,vector<int>(len2));
    for (int i = 0; i < len1; ++i) vec[i][0] = i;
    for (int j = 0; j < len2; ++j) vec[0][j] = j;
    for (int i = 1; i < len1; ++i)
    {
      for (int j = 1; j < len2; ++j)
      {
        if (word1[i - 1] == word2[j - 1]) vec[i][j] = vec[i - 1][j - 1];
        else vec[i][j] = vec[i - 1][j - 1] + 1;
        vec[i][j] = min(vec[i][j],min(vec[i-1][j]+1,vec[i][j-1]+1));
      }
    }
    return vec[len1 - 1][len2 - 1];
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