#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> res;
    int lidx, ridx, tmp;
    lidx = findl(A, 0, n - 1, target);
    if (lidx == -1) return { -1, -1 };
    ridx = findr(A, lidx+1, n - 1, target);
    res.push_back(lidx);
    res.push_back(ridx);
    return res;
  }
  int findl(int a[], int l, int r, const int &target)
  {
    while (l <= r)
    {
      int mid = (l + r) >> 1;
      if (a[mid] >= target) r = mid - 1;
      else l = mid + 1;
    }
    if (a[l] == target) return l;
    else return -1;
  }
  int findr(int a[], int l, int r, const int &target)
  {
    while (l <= r)
    {
      int mid = (l + r) >> 1;
      if (a[mid] > target) r = mid - 1;
      else l = mid + 1;
    }
    if (a[r] == target) return r;
    else return -1;
  }
};

int main()
{
  Solution slu;
  int input[] = { 3, 5, 5, 5, 5, 5,7 };
  int target = 2;
  vector<int> res = slu.searchRange(input, 7, target);
  cout << res[0] << "  " << res[1] << endl;
  system("pause");
}