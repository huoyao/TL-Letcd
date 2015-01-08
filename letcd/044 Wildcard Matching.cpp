#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (strlen(p) == 1 && p[0] == '*' || strlen(p) == 2 && p[0] == '?' && p[1] == '*' && strlen(s) > 0) return true;
    const char *star = NULL;
    const char *record = NULL;
    while (*s)
    {
      if (*p == '?' || *p == *s){ p++; s++; continue; }
      if (*p == '*'){ star = p++; record = s; continue; }
      if (star){ p = star + 1; s = record++; continue; }
      return false;
    }
    while (*p == '*') ++p;
    return !*p;
  }
};

int main()
{
  Solution slu;
  char input[] = "aa",target[] = "a?*";
  bool res = slu.isMatch(input, target);
  cout << res << endl;
  system("pause");
}