#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int len = s.length(), idx = 0, res=0;
    while (idx < len) {res = res * 26 + s[idx++] - 'A' + 1;}
    return res;
  }
};

int main()
{
  Solution slu;
  string str = "Z";
  int res = slu.titleToNumber(str);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
