#if 0
#include <iostream>
#include <cstdint>
using namespace std;

class Solution
{
public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    while(n)
    {
      n &= n - 1;
      ++res;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  uint32_t input = 1;
  int res = slu.hammingWeight(input);
    cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
