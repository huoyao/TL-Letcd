#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};

int main()
{
  Solution slu;
  int target = 79;
  int res = slu.trailingZeroes(target);
  cout << res << endl;
  system("pause");
  return 0;
}