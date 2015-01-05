#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
  int strStr(char *haystack, char *needle) {
    int plen = strlen(needle), slen = strlen(haystack), k = -1, i=0, j=0;
    if (plen == 0) return 0;
    vector<int> next(plen);
    next[0] = -1;
    while (i < plen-1)
    {
      if (k == -1 || needle[k] == needle[i])
      {
        ++k;
        ++i;
        next[i] = k;
      }
      else
        k = next[k];
    }
    i = 0;
    while (i < slen && j < plen)
    {
      if (j == -1 || haystack[i] == needle[j])
      {
        ++i;
        ++j;
      }
      else
        j = next[j];
    }
    if (j == plen) return i - j;
    else return -1;
  }
};

int main()
{
  Solution slu;
  char hsy[] = "eeeeeeeddeedd", ned[] = "eedd";
  int res = slu.strStr(hsy, ned);
  cout << res << endl;
  system("pause");
}