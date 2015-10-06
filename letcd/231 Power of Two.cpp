#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool isPowerOfTwo(int n) {
    return n > 0 && !(n&(n - 1));
  }
};

int main()
{
  Solution slu;
  int target = 128;
  bool res = slu.isPowerOfTwo(target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}

#endif
