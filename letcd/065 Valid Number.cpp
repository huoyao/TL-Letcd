#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isNumber(const char *s) {
    bool has_exp = false, has_space = false, has_num = false,has_dot=false;
    while (*s == ' ') ++s;
    if (*s == '+' || *s == '-') ++s;
    while (*s != '\0')
    {
      if (isdigit(*s))
      {
        if (has_space) return false;
        else has_num = true;
      }
      else if (*s == ' ')
        has_space = true;
      else if (*s == '.')
      {
        if (!has_dot && !has_space && !has_exp) has_dot = true;
        else return false;
      }
      else if (*s == 'e')
      {
        if (!has_exp && !has_space && has_num)
        {
          has_exp = true;
          has_num = false;
          if (*(s + 1) == '-' || *(s + 1) == '+') ++s;
        }
        else return false;
      }
      else return false;
      ++s;
    }
    return has_num;  //mark
  }
};

int main()
{
  Solution slu;
  char input[] = "   0.3452  ";
  bool res = slu.isNumber(input);
  cout << res<<endl;
  system("pause");
}
#endif
