#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(int A[], int n) {
    if (n <= 1) return 0;
    int step = 0, maxreach = A[0], lastid = n - 1, centerid = 0;
    while (maxreach < lastid)
    {
      int id;
      for (int i = 1; i <= A[centerid]; ++i)
      if (A[centerid + i] + centerid + i>maxreach)
      {
        id = centerid + i;
        maxreach = A[centerid + i] + centerid + i;
      }
      centerid = id;
      step++;
    }
    return step + 1;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 7, 11, 15 };
  int target = 4;
  int res = slu.jump(input, target);
  cout << res << endl;
  system("pause");
}