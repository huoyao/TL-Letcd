#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; ++i)
    {
      two |= one&A[i];
      one ^= A[i];
      three = one &two;
      one &= ~three;
      two &= ~three;
    }
    return one;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 2, 11, 2 };
  int target = 4;
  int res = slu.singleNumber(input, target);
  cout << res<<endl;
  system("pause");
}