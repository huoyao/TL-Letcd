#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> mapidx = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, {'M',1000} };
    int len = s.length(), tmp = mapidx[s[0]], res = tmp;
    if (len == 1) return tmp;
    for (int i = 1; i < len; ++i)
    {
      res += mapidx[s[i]];
      if (mapidx[s[i]]>mapidx[s[i - 1]]) res -= 2 * mapidx[s[i - 1]];
    }
    return res;
  }
};

int main()
{
  Solution slu;
  string target = "MDCCCLXXXIV";
  int res = slu.romanToInt(target);
  cout << res << endl;
  system("pause");
}