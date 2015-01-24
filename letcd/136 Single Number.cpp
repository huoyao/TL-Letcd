#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    if (n == 0) return 0;
    int res=A[0];
    for (int i = 1; i < n; ++i)
      res ^= A[i];
    return res;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, 2, 1, 3,3 };
  int target = 5;
  int res = slu.singleNumber(input, target);
  cout << res<<endl;
  system("pause");
}