#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    int lmax = 0, left = 0, rmax = 0, right = n - 1.res = 0;
    while (left <= right)
    {
      if (A[left] <= A[right])
      {
        if (A[left] >= lmax) lmax = A[left];
        else res += maxleft - A[left];
        ++left;
      }
      else
      {
        if (A[right] >= rmax) rmax = A[right];
        else res += rmax - A[right];
        ++right;
      }
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 0, 7, 0, 3 };
  int target = 5;
  int res = slu.trap(input, target);
  cout << res << endl;
  system("pause");
}