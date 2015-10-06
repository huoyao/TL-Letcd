#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    vector<vector<bool> > row(9, vector<bool>(9, true)), col(9, vector<bool>(9, true)), block(9, vector<bool>(9, true));
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] == '.') continue;
        int idx = board[i][j] - '1';
        row[i][idx] = col[j][idx] = block[i - i % 3 + j / 3][idx] = false;
      }
    }
    fillsudo(0,0,board,row,col,block);
  }
  bool fillsudo(int i, int j, vector<vector<char> > &bd, vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &block)
  {
    if (j == 9){ ++i; j = 0; }
    if (i == 9 && j == 0) return true;
    else if (bd[i][j] != '.')
      return fillsudo(i, j + 1, bd, row, col, block);
    else
    {
      for (int k = 0; k < 9; ++k)
      {
        if (row[i][k] && col[j][k] && block[i - i % 3 + j / 3][k])
        {
          bd[i][j] = '1' + k;
          row[i][k] = false;
          col[j][k] = false;
          block[i - i % 3 + j / 3][k] = false;
          if (fillsudo(i, j + 1, bd, row, col, block)) return true;
          else
          {
            bd[i][j] = '.';
            row[i][k] = true;
            col[j][k] = true;
            block[i - i % 3 + j / 3][k] = true;
          }
        }
      }
      return false;
    }
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input(9,vector<char>(9,'.'));
  input[0][0] = '5';
  input[0][1] = '3';
  input[0][4] = '7';
  input[1][0] = '6';
  input[1][3] = '1';
  input[1][4] = '9';
  input[1][5] = '5';
  input[2][1] = '9';
  input[2][2] = '8';
  input[2][7] = '6';
  input[3][0] = '8';
  input[3][4] = '6';
  input[3][8] = '3';
  input[4][0] = '4';
  input[4][3] = '8';
  input[4][5] = '3';
  input[4][8] = '1';
  input[5][0] = '7';
  input[5][4] = '2';
  input[5][8] = '6';
  input[6][1] = '6';
  input[6][6] = '2';
  input[6][7] = '8';
  input[7][3] = '4';
  input[7][4] = '1';
  input[7][5] = '9';
  input[7][8] = '5';
  input[8][4] = '8';
  input[8][7] = '7';
  input[8][8] = '9';
  slu.solveSudoku(input);
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
      cout << input[i][j] << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
