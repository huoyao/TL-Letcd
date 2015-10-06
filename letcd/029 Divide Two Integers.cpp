#if 0
#include <iostream>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1 || divisor == 0) return INT_MAX;
    long long a = abs(static_cast<long long>(dividend)),
              b=abs(static_cast<long long>(divisor)),res=0;
    while (a >= b)
    {
      long long c = b;
      for (int i = 0; a >= c;++i, c <<= 1)
      {
        a -= c;
        res += 1 << i;
      }
    }
    int tag = (dividend>0)^(divisor>0);
    if(tag == 1) res = -res;
    return static_cast<int>(res);
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
#endif
