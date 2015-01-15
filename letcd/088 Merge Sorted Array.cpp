#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int idx = m + n - 1;
    while (n > 0)
    {
      if (m>0 && A[m - 1] > B[n - 1]) //mark for "m>0"
        A[idx--] = A[--m];
      else
        A[idx--] = B[--n];
    }
  }
};

int main()
{
  Solution slu;
  int input[10] = { 0, 0, 3 }, target[] = { -1, 1, 1, 1, 2, 3 };
  slu.merge(input,3, target,6);
  for (auto &t : input)
    cout << t << "  ";
  cout << endl;
  system("pause");
}