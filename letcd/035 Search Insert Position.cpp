#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) >> 1;
      if (A[mid] > target) r = mid-1;
      else if (A[mid] < target)l = mid + 1;
      else return mid;
    }
    return l;
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