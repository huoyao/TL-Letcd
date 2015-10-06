#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string S, string T) {
    int slen = S.length(), tlen = T.length(), start, end, minwindow = slen + 1, cnt = 0;
    string res = "";
    if (slen == 0 || tlen == 0) return res;
    vector<int> needstr(256, 0), hasstr(256, 0);
    for (int i = 0; i < tlen; ++i)
      ++needstr[T[i]];
    for (start = 0, end = 0; end < slen; ++end)
    {
      char ch = S[end];
      if (needstr[ch] == 0) continue;
      ++hasstr[ch];
      if (hasstr[ch] <= needstr[ch]) ++cnt;
      if (cnt == tlen)
      {
        ch = S[start];
        while (needstr[ch] == 0 || hasstr[ch]>needstr[ch])
        {
          if (hasstr[ch] > needstr[ch]) --hasstr[ch];
          ++start;
          ch = S[start];
        }
        int len = end - start + 1;
        if (len < minwindow)
        {
          minwindow = len;
          res = S.substr(start, len);
        }
      }
    }
    return res;
  }
};
int main()
{
  Solution slu;
  string input = "abcfjdskadsadsa";
  string target = "abcd";
  string res = slu.minWindow(input, target);
  cout << res<<endl;
  system("pause");
}
#endif
