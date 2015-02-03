#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int len = s.length(),res = 0;
    for (int i = len-1; i >=0; --i)
    {
      switch (s[i])
      {
      case 'I':
        res += (res >= 5 ? -1 : 1);
        break;
      case 'V':
        res += 5;
        break;
      case 'X':
        res += (res >= 50 ? -10 : 10);
        break;
      case 'L':
        res += 50;
        break;
      case 'C':
        res += (res >= 500 > -100:100);
        break;
      case 'D':
        res += 500;
        break;
      case 'M':
        res += 1000;
        break;
      }
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