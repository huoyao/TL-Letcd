#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int calculate(string s) {
    int pre_sign = 1,res=0,cur_num=0,next_num=0;
    const size_t &len = s.length();
    for(size_t i = 0;i < len;++i)
    {
      const char &c = s[i];
      if(c == ' ') continue;
      switch(c)
      {
      case '+':
      case '-':
        res += cur_num*pre_sign;
        pre_sign = c=='+'?1:-1;
        cur_num = 0;
        break;
      case '/':
      case '*':
        while(i < len - 1 && s[i + 1] == ' ') ++i;
        while(i < len - 1 && isdigit(s[i + 1])) next_num = next_num * 10 + s[++i] - '0';
        if(c == '/') cur_num /= next_num;
        else cur_num *= next_num;
        next_num = 0;
        break;
      default:
        cur_num = cur_num * 10 + c - '0';
        break;
      }
    }
    res += cur_num*pre_sign;
    return res;
  }
};

int main()
{
  Solution slu;
  string input = " 3 + 5 / 2 ";
  int res = slu.calculate(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}