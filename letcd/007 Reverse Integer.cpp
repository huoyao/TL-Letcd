#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long res = 0;
    while (x)
    {
      res = res * 10 + x%10;
      if (res > INT_MAX || res<INT_MIN) return 0;
      x/=10;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 1, 7, 11, -15 };
  int res = slu.reverse(vecnum[3]);
  cout << res << endl;
  system("pause");
}
#endif
