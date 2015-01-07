#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bisearch(int a[],const int &n,const int &target)
{
  int l = 0, r = n - 1;
  while (l <= r)
  {
    int mid = (l + r) >> 1;
    if (a[mid] == target) return mid;
    if (a[mid] > target) r -= 1;
    else l += 1;
  }
  return max(l,r);
}

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    return bisearch(A,n,target);
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 7, 11, 15 };
  int target = 3;
  int res = slu.searchInsert(input, 4,target);
  cout << res << endl;
  system("pause");
}