#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.empty()) return 0;
    vector<int> dict(256,0);
    int beg = 0, len = 1, cnt = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      ++dict[s[i]];
      if (dict[s[i]] == 1)
      {
        ++cnt;
        while (cnt>2)
        {
          --dict[s[beg]];
          if (dict[s[beg]] == 0) --cnt;
          ++beg;
        }
      }
      len = max(len,i-beg+1);
    }
    return len;
  }
};

int main()
{
  Solution slu;
  string input = "eohfhfhf";
  int res = slu.lengthOfLongestSubstringTwoDistinct(input);
  cout << res << endl;
  system("pause");
  return 0;
}