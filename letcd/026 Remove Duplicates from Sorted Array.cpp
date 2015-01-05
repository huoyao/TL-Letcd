#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n <=1) return n;
    int pre = A[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
      if (A[i] == pre) continue;
      pre = A[i];
      A[cnt++] = A[i];
    }
    return cnt;
  }
};

int main()
{
  Solution slu;
  int  vecnum[] = { 2, 24, 22, 15 };
  int target = 4;
  int res = slu.removeDuplicates(vecnum, target);
  cout << res << endl;
  system("pause");
}
