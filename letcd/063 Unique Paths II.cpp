#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid.size() ? obstacleGrid[0].size() : 0;
    if (m == 0 || n == 0) return 0;
    vector<vector<int> > vec(m, vector<int>(n, 1));
    vec[0][0] = obstacleGrid[0][0] ? 0 : 1;  //mark
    for (int i = 1; i < n; ++i)
      vec[0][i] = obstacleGrid[0][i] ? 0 : vec[0][i - 1];  //mark
    for (int i = 1; i < m; ++i)
      vec[i][0] = obstacleGrid[i][0] ? 0 : vec[i-1][0];
    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        vec[i][j] = 0;
        if (obstacleGrid[i][j]) continue;  //mark
        if (obstacleGrid[i - 1][j] == 0) vec[i][j] += vec[i - 1][j];
        if (obstacleGrid[i][j - 1] == 0) vec[i][j] += vec[i][j - 1];
      }
    }
    return vec[m - 1][n - 1];
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