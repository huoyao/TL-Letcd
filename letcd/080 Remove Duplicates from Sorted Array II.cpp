#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n <= 2) return n;
    int start = 0, idx = 0, crr = A[0], cnt = 0;
    for (int i = 0; i < n; ++i)
    {
      if (crr == A[i])
      {
        if (cnt < 2)
        {
          ++cnt;
          A[start++] = A[i];
        }
      }
      else
      {
        cnt = 1;
        A[start++] = A[i];
        crr = A[i];
      }
    }
    for (int i = n - 1; i >= start; --i)
      A[i] = -1;
    return start;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 2, 2, 7, 7, 7, 11, 11, 15 };
  int target = 9;
  int res = slu.removeDuplicates(input, target);
  cout << res << endl;
  system("pause");
}