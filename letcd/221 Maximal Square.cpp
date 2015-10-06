#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int num_rows = matrix.size(), num_cols = matrix[0].size();
    vector<vector<int>> rec(2,vector<int>(num_cols,0));
    int maxsize=0;
    for(size_t i = 0;i < num_cols;++i)
    {
      rec[0][i] = matrix[0][i] - '0';
      maxsize = max(maxsize, rec[0][i]);
    }
    int pre = 0, cur = 1;
    for(size_t i = 1;i < num_rows;++i)
    {
      rec[cur][0] = matrix[i][0] - '0';
      maxsize = max(maxsize, rec[cur][0]);
      for(size_t j = 1;j < num_cols;++j)
      {
        if(matrix[i][j] == '1')
          rec[cur][j] = min(rec[cur][j - 1], min(rec[pre][j], rec[pre][j - 1])) + 1;
        else rec[cur][j] = 0;
        maxsize = max(maxsize, rec[cur][j]);
      }
      swap(pre, cur);
    }
    return maxsize*maxsize;
  }
};

int main()
{
  Solution slu;
  vector<vector<char>> input = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' },
  { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
  int res = slu.maximalSquare(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
