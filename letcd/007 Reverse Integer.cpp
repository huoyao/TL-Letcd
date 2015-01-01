#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int tag = 0;
    if (x == 0) return 0;
    if (x < 0) tag = 1;
    long long res = 0, maxnum = pow(2., 31) - 1;
    string s;
    stringstream str;
    str << x;
    str >> s;
    int idx = s.length() - 1;
    while (s[idx] == '0')--idx;
    while (idx >= tag)
    {
      res = res * 10 + s[idx] - '0';
      if (res > maxnum || tag && res > maxnum + 1) return 0;
      --idx;
    }
    int resint = res;
    return tag ? -resint : resint;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 1, 7, 11, 15 };
  int res = slu.reverse(vecnum[0]);
  cout << res << endl;
  system("pause");
}