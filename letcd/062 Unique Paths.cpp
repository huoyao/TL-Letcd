#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> vec(n, 1);
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
       vec[j]+=vec[j - 1];
    return vec[n-1];
  }
};

int main()
{
  Solution slu;
  int input = 23;
  int target = 12;
  int res = slu.uniquePaths(input, target);
  cout << res << endl;
  system("pause");
}