#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    string res;
    if ((numerator > 0) ^ (denominator > 0)) res = "-";
    long long num = abs(static_cast<long long>(numerator));
    long long denum = abs(static_cast<long long>(denominator));
    res += to_string(num / denum);
    num %= denum;
    if (num) res += ".";
    unordered_map<int, int > mapidx;
    while (num)
    {
      if (mapidx.count(num))
      {
        res.insert(mapidx[num],1,'(');
        res += ")";
        break;
      }
      mapidx[num] = res.size();
      num *= 10;
      res += to_string(num / denum);
      num %= denum;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int input = -2147483648;
  int target = 1;
  string res = slu.fractionToDecimal(input, target);
  cout << res << endl;
  system("pause");
  return 0;
}