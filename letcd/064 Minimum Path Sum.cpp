#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    if (m == 0 || n == 0) return 0;
    for (int i = 1; i < n; ++i)
      grid[0][i] += grid[0][i - 1];
    for (int j = 1; j < m; ++j)
      grid[j][0] += grid[j - 1][0];
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
       grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    return grid[m - 1][n - 1];
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 0, 1, 2 }, { 2, 3, 4 }, { 5, 6, 7 } };
  int res = slu.minPathSum(input);
  cout << res << endl;
  system("pause");
}
#endif
