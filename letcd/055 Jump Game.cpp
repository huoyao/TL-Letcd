#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    if (n <= 1) return true;
    int maxreach = A[0], lastid = n - 1, centerid = 0;
    while (maxreach < lastid )
    {
      int id=-1;
      if (A[centerid] == 0) break;
      for (int i = 1; i <= A[centerid]; ++i)
      if (A[centerid + i] + centerid + i>=maxreach)
      {
        id = centerid + i;
        maxreach = A[centerid + i] + centerid + i;
      }
      centerid = id;
    }
    return maxreach>=lastid;
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