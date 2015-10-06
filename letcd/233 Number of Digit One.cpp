#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int countDigitOne(int n) {
    int cnt = 0;
    for(long long m = 1;m <= n;m*=10)
    {
      const int res = n / m;
      cnt += (res + 8) / 10 * m + (res % 10 == 1)*(n%m + 1);
    }
    return cnt;
  }
};

int main()
{
  Solution slu;
  int n = 11;
  int res = slu.countDigitOne(n);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
