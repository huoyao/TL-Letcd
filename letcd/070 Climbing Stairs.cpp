#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 1, b = 2,c,cnt=3;
    while (cnt <= n)
    {
      c = a + b;
      a = b;
      b = c;
      ++cnt;
    }
    return c;
  }
};

int main()
{
  Solution slu;
  int input = 5;
  int res = slu.climbStairs(input);
  cout << res<<endl;
  system("pause");
}