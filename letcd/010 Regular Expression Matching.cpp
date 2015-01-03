#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (*p == '\0') return *s == '\0';
    if (*(p + 1) == '*')
    {
      while (*p == *s || (*p == '.' && *s != '\0'))
      {
        if (isMatch(s, p + 2)) return true;
        ++s;
      }
      return isMatch(s, p + 2);
    }
    else
    {
      if (*p == *s || (*p == '.' && *s != '\0')) return isMatch(s + 1, p + 1);
      else return false;
    }
  }
};

int main()
{
  Solution slu;
  char s[] = "aaab", p[] = "a*";
  bool res = slu.isMatch(s, p);
  cout << res << endl;
  system("pause");
}