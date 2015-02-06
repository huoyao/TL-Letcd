#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    vector<vector<bool> > col(9, vector<bool>(9, false)), block(9, vector<bool>(9, false));
    for (int i = 0; i < 9; ++i)
    {
      vector<bool> row(9, false);
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] == '.') continue;
        int idx = board[i][j] - '1', bidx = i - i % 3 + j / 3;
        if (row[idx] || col[j][idx] || block[bidx][idx]) return false;
        else row[idx] = col[j][idx] = block[bidx][idx] = true;
      }
    }
    return true;
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input(9);
  for (int i = 0; i < 9; ++i)
  {
    vector<char> vec(9);
    for (int j = 0; j < 9; ++j)
      vec[j]='1'+j;
    input[i] = vec;
  }
  bool res = slu.isValidSudoku(input);
  cout << res << endl;
  system("pause");
}