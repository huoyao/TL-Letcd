#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int all = m + n;
    if (all & 0x1)
      return findkthelem(A, m, B, n, all / 2 + 1);
    else
      return (findkthelem(A, m, B, n, all / 2) + findkthelem(A, m, B, n, all / 2 + 1)) / 2;
  }
  double findkthelem(int A[], int m, int B[], int n,int k)
  {
    if (m > n) return findkthelem( B, n, A, m, k);
    if (m == 0) return B[k - 1];
    if (k == 1) return min(A[0],B[0]);
    int a_kth = min(k / 2, m), b_kth = k - a_kth;
    if (A[a_kth - 1]<B[b_kth - 1]) return findkthelem(A+a_kth,m-a_kth,B, n, k-a_kth);
    else if(A[a_kth - 1]>B[b_kth - 1]) return findkthelem(A , m, B+b_kth, n-b_kth, k - b_kth);
    else return A[a_kth-1];
  }
};

int main()
{
  Solution slu;
  int A[] = { 1, 2, 3, 4, 5 }, b[] = { 44, 55, 66 };
  double res = slu.findMedianSortedArrays(A,5,b,3);
  cout << res << endl;
  system("pause");
}