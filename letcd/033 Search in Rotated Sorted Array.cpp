#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int a[], int l, int r, const int &target)
{
  if (l > r) return -1;
  int idx = -1;
  if (a[l] <= a[r])
  {
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (a[mid] == target) return mid;
      if (target>a[mid]) l = mid + 1;
      else r = mid - 1;
    }
  }
  else
  {
    int mid = (l + r) / 2;
    if (a[mid] == target) return mid;
    idx = find(a, l, mid - 1, target);
    idx = idx == -1 ? find(a, mid + 1, r, target) : idx;
  }
  return idx;
}

class Solution {
public:
  int search(int A[], int n, int target) {
    return find(A, 0, n - 1, target);
  }
};

int main()
{
  Solution slu;
  int input[] = { 3, 5, 1 };
  int target = 3;
  int res = slu.search(input, 4, target);
  cout << res << endl;
  system("pause");
}