#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    for (int i = 0; i < 9; ++i)
    {
      vector<bool> vec(10,false);
      for (int j = 0; j < 9; ++i)
      {
        if (board[i][j] == '.') continue;
        int idx = board[i][j] - '0';
        if (vec[idx]) return false;
        else vec[idx] = true;
      }
      vector<bool> vec1(10, false);
      for (int j = 0; j < 9; ++i)
      {
        if (board[j][i] == '.') continue;
        int idx = board[j][i] - '0';
        if (vec1[idx]) return false;
        else vec1[idx] = true;
      }
    }
    for (int i = 0; i < 9; i += 3)
    {
      for (int j = 0; j < 9; j += 3)
      {
        vector<bool> vec(10, false);
        for (int k = i; k < i + 3; ++k)
        {
          for (int t = j; t < j + 3; ++t)
          {
            if (board[k][t] == '.') continue;
            int idx = board[k][t] - '0';
            if (vec[idx]) return false;
            else vec[idx] = true;
          }
        }
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