#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    int i = 0, maxreach = 0;
    for (; i < n && i <= maxreach && maxreach < n - 1; ++i)
      maxreach = max(maxreach,i+A[i]);
    return maxreach>=n-1;
  }
};

int main()
{
  Solution slu;
  int input[] = { 3, 2, 1, 0, 4 };
  int target = 5;
  bool t = slu.canJump(input, target);
  cout << t;
  cout << endl;
  system("pause");
}
#endif
