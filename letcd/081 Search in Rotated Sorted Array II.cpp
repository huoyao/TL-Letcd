#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bisech(int start, int end, int A[], const int &target)
{
  if (start > end) return false;
  if (start == end) return A[start] == target;
  if (A[start] < A[end])
  {
    while (start <= end)
    {
      int mid = (start + end) >> 1;
      if (A[mid] == target) return true;
      if (A[mid] > target) end = mid - 1;
      else start = mid + 1;
    }
    return false;
  }
  else
  {
    int mid = (start + end) >> 1;
    if (A[mid] == target) return true;
    return bisech(start, mid-1, A, target) || bisech(mid+1, end, A, target);
  }
}

class Solution {
public:
  bool search(int A[], int n, int target) {
    if (n <= 0) return false;
    return bisech(0, n - 1, A, target);
  }
};

int main()
{
  Solution slu;
  int input[] = { 11, 15, 1, 2, 3, 11, 11 };
  int target = 7;
  bool res = slu.search(input, target, 15);
  cout << res << endl;
  system("pause");
}