#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
      if (A[i] == elem) continue;
      A[idx++] = A[i];
    }
    return idx;
  }
};

int main()
{
  Solution slu;
  int vecnum[] = { 2, 7, 11, 15 };
  int target = 4,re=2;
  int res = slu.removeElement(vecnum, target,re);
  cout << res << endl;
  system("pause");
}