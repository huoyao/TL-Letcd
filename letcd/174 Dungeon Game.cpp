#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    dungeon[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : abs(dungeon[m - 1][n - 1]) + 1;
    for (int i = n-2; i >= 0; --i)
      dungeon[m - 1][i] = max(dungeon[m - 1][i + 1] - dungeon[m - 1][i],1);
    for (int i = m - 2; i >= 0; --i)
      dungeon[i][n - 1] = max(dungeon[i + 1][n - 1] - dungeon[i][n - 1],1);
    for (int i = m-2; i >= 0;--i)
      for (int j = n-2; j >= 0; --j)
        dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j],1);
    return dungeon[0][0];
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
  int res = slu.calculateMinimumHP(input);
  cout << res << endl;
  system("pause");
  return 0;
}