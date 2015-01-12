#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int sqrt(int x) {
    if (x == 1) return 1;
    int n = x / 2,a=1,b=n;
    while (a <= b)
    {
      int midid = (a + b) >> 1;
      long long mid = (long long)midid*midid;
      if (x == mid) return midid;
      if (x>mid) a=midid+1;
      else b=midid-1;
    }
    return min(a, b);
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