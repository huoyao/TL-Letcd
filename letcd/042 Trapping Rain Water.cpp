#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void water(int &sum,const int A[],const int &n,int &i)
{
  int curidx = i, maxidx = i+1, lastid = i+1,curval=A[i],tmp=0;
  while (lastid < n && A[lastid] < curval)
  {
    if (A[lastid]>A[maxidx]) maxidx = lastid;
    ++lastid;
  }
  if (lastid < n) maxidx = lastid;
  int val = min(curval,A[maxidx]);
  for (int idx = i + 1; idx < maxidx; ++idx)
    tmp += (val-A[idx]);
  sum +=tmp;
  i = maxidx;
}

class Solution {
public:
  int trap(int A[], int n) {
    if (n < 2) return 0;
    int sum = 0;
    int i = 0;
    while (i < n - 1) water(sum, A, n, i);
    return sum;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2,0, 7, 0, 3 };
  int target = 5;
  int res = slu.trap(input, target);
  cout << res << endl;
  system("pause");
}