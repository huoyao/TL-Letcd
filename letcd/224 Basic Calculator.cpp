#if 0
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int calculate(string s) {
    if(s.length() == 0) return 0;
    stack<int> pre_signs;
    pre_signs.push(1);
    int cur_num = 0, res = 0,cur_sign=1;
    for(size_t i = 0;i < s.length();++i)
    {
      const char &c = s[i];
      if(isdigit(c))
        cur_num = cur_num * 10 + c - '0';
      else if(c == '+' || c == '-')
      {
        res += pre_signs.top()*cur_sign*cur_num;
        cur_num = 0;
        cur_sign = c == '+' ? 1 : -1;
      } else if(c == '(')
      {
        pre_signs.push(pre_signs.top()*cur_sign);
        cur_sign = 1;
      } else if(c == ')')
      {
        res += pre_signs.top()*cur_sign*cur_num;
        cur_num = 0;
        pre_signs.pop();
        cur_sign = 1;
      }
    }
    if(cur_num) res += pre_signs.top()*cur_sign*cur_num;
    return res;
  }
};

int main()
{
  Solution slu;
  string s = "2147483647";
  int res = slu.calculate(s);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
