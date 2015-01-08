#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    int curnum;
    for (int i = 0; i < n; ++i)
    {
      curnum = A[i];
      while (curnum>0 && curnum <= n && A[curnum - 1] != curnum)
      {
        swap(A[i], A[curnum - 1]);
        curnum = A[i];
      }
    }
    for (int i = 0; i < n; ++i)
      if (A[i] != i + 1) return i + 1;
    return n+1;
  }
};

int main()
{
  Solution slu;
  int input[] = { -1,1,2, 7, 11, 15 };
  int target = 6;
  int res = slu.firstMissingPositive(input, target);
  cout << res << endl;
  system("pause");
}