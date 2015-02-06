#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int search(int A[], int n, int target) {
    int beg = 0, end = n - 1;
    while (beg <= end)
    {
      int mid = (beg + end) >> 1;
      if (A[mid] == target) return mid;
      if (A[beg] <= A[mid])
        if (A[beg] <= target && target < A[mid]) end = mid - 1;
        else beg = mid + 1;
      else
        if (A[mid] < target && target <= A[end]) beg = mid + 1;
        else end = mid - 1;
    }
    return -1;
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