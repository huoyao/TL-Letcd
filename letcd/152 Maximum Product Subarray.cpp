#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(int A[], int n) {
    if (n == 0) return 0;
    int maxnum = A[0], curmax = A[0], curmin = A[0];
    for (int i = 1; i < n; ++i)
    {
      int tmp = curmin*A[i];
      curmin = min(A[i],min(tmp,curmax*A[i]));
      curmax = max(A[i],max(tmp,curmax*A[i]));
      maxnum = max(maxnum,curmax);
    }
    return maxnum;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, -7, 11, 15 };
  int target = 4;
  int res = slu.maxProduct(input, target);
  cout << res << endl;
  system("pause");
}