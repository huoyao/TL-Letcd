#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    vector<vector<int> > &obs = obstacleGrid;
    int m = obs.size(), n = obs.size() ? obs[0].size() : 0;
    if (m == 0 || n == 0 || obs[0][0] || obs[m-1][n-1]) return 0;
    obs[0][0] = 1;
    for (int i = 1; i < n; ++i)
      obs[0][i] = obs[0][i] ? 0 : obs[0][i - 1];  //mark
    for (int i = 1; i < m; ++i)
      obs[i][0] = obs[i][0] ? 0 : obs[i - 1][0];
    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        if (obs[i][j]) { obs[i][j] = 0; continue; }
        obs[i][j] = obs[i - 1][j] + obs[i][j - 1];
      }
    }
    return obs[m - 1][n - 1];
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 1, 0 } };
  int res = slu.uniquePathsWithObstacles(input);
  cout << res << endl;
  system("pause");
}
#endif
