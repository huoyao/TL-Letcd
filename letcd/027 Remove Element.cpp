#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int idx = 0;
    while (idx < n)
    {
      if (A[idx] == elem) { A[idx] = A[n - 1]; --n; }
      else ++idx;
    }
    return n;
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