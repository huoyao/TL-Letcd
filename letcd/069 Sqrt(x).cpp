#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int sqrt(int x) {
    long long ans = 0, bit = 1L << 15;
    while (bit > 0)
    {
      ans |= bit;
      if (ans*ans > x) ans ^= bit;   //recovery ans
      bit >>= 1;
    }
    return (int)ans;
  }
};

int main()
{
  Solution slu;
  int input = 2147395599;
  int res = slu.sqrt(input);
  cout << res << endl;
  system("pause");
}
#endif
