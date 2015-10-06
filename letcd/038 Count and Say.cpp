#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string str = "1";
    while (--n) str = convert(str);
    return str;
  }
  string convert(const string &str)
  {
    string st;
    int len = str.length();
    for (int i = 0; i < len; ++i)
    {
      int cnt = i;
      while (i + 1 < len && str[i] == str[i + 1])++i;
      cnt = i - cnt + 1;
      st += ('0' + cnt);
      st += str[i];
    }
    return st;
  }
};

int main()
{
  Solution slu;
  int target = 6;
  string res = slu.countAndSay(target);
  cout << res << endl;
  system("pause");
}
#endif
