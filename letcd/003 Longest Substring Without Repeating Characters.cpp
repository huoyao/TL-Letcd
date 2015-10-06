#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> charIdx(256,-1);
    int longest=0, maxdiff = 0,len=s.length();
    for (int i = 0; i < len; ++i)
    {
      maxdiff = max(maxdiff,charIdx[s[i]]+1);
      longest = max(longest,i-maxdiff+1);
      charIdx[s[i]] = i;
    }
    return longest;
  }
};

int main()
{
  Solution slu;
  string str = "kokok";
  int res = slu.lengthOfLongestSubstring(str);
  cout <<res<< endl;
  system("pause");
}
#endif
