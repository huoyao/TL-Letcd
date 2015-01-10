#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  double pow(double x, int n) {
    double res = 1;
    int idx = abs(n);
    while (idx>0)
    {
      if (idx % 2)
        res *= x;
      idx /= 2;
      x *= x;
    }
    return n >= 0 ? res : 1. / res;
  }
};

int main()
{
  Solution slu;
  double input = 0.1;
  int target = 3;
  double res = slu.pow(input, target);
  cout << res << endl;
  system("pause");
}