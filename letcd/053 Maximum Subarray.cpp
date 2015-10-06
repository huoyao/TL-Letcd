#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxSubArray(int A[], int n) {
    int maxval = A[0], val = A[0];
    for (int i = 1; i < n; ++i)
    {
      if (val <= 0)
        val = A[i];
      else
        val += A[i];
      if (val>maxval) maxval = val;
    }
    return maxval;
  }
};

int main()
{
  Solution slu;
  int input[] = { -2, -7, -11, -1 };
  int target = 4;
  int res = slu.maxSubArray(input, target);
  cout << res << endl;
  system("pause");
}
#endif
