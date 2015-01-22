#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int minCut(string s) {
    int len = s.length();
    if (len<2) return 0;
    vector<int> minnum(len+1,0);
    vector<vector<bool> > isPali(len,vector<bool>(len,false));
    for (int i = len - 1; i >= 0; --i)
    {
      minnum[i] = len - i;
      for (int j = i; j < len; ++j)
      {
        if (s[i] == s[j])
        {
          if (j - i < 2 || isPali[i + 1][j - 1])
          {
            isPali[i][j] = true;
            minnum[i] = min(minnum[i],minnum[j+1]+1);
          }
        }
      }
    }
    return minnum[0] - 1;
  }
};

int main()
{
  Solution slu;
  string input = "bb";
  int res = slu.minCut(input);
  cout << res << endl;
  system("pause");
}