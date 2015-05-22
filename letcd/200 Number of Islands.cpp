#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>>& grid) {
    numrow = grid.size(), res = 0;
    for(size_t i = 0;i < numrow;++i)
    {
      int numcol = grid[i].size();
      for(size_t j = 0;j < numcol;++j)
      {
        if(grid[i][j] == '1') { find(grid, i, j); ++res; }
      }
    }
    return res;
  }
  void find(vector<vector<char>>& grid, const int &idx_i, const int &idx_j)
  {
    if(idx_i < 0 || idx_i >= numrow || idx_j < 0 || idx_j >= grid[idx_i].size() || grid[idx_i][idx_j] != '1') return;
    grid[idx_i][idx_j] = '2';
    find(grid, idx_i + 1, idx_j);
    find(grid, idx_i - 1, idx_j);
    find(grid, idx_i, idx_j + 1);
    find(grid, idx_i, idx_j - 1);
  }
private:
  int numrow, res;
};

int main()
{
  Solution slu;
  vector<vector<char>> input = { { '1', '1', '0', '0' }, { '1', '0', '0', '0' },
  { '1', '0', '0', '0' }, { '0', '0', '1', '0' } };
  int res = slu.numIslands(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}