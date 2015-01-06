#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    long a = abs((long long)dividend),b=abs((long long) divisor),res=0;
    while (a >= b)
    {
      long long c = b;
      for (int i = 0; a >= c;++i, c <<= 1)
      {
        a -= c;
        res += 1 << i;
      }
    }
    int tag = (dividend^divisor) >> 31 ? -1 : 1;
    res *= tag;
    if (res > INT_MAX || res < INT_MIN) return INT_MAX;
    else return (int)res;
  }
};

int main()
{
  Solution slu;
  int vecnum = 10;
  int target = 3;
  int res = slu.divide(vecnum, target);
  cout << res << endl;
  system("pause");
}