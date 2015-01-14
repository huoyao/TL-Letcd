#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find(const int &i, const int &j, const string &wd, vector<vector<char> > &board,int k)
{
  if (k == wd.size())
    return true;
  if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && board[i][j] == wd[k])
  {
    char tmp = board[i][j];
    board[i][j] = '*';
    bool up = find(i+1, j, wd, board, k+1);
    bool down = find(i - 1, j, wd, board, k + 1);
    bool left = find(i, j-1, wd, board, k + 1);
    bool right = find(i , j+1, wd, board, k + 1);
    if (up || down || left || right) return true;
    else
    {
      board[i][j] = tmp;
      return false;
    }
  }
  return false;
}

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    if (board.size() == 0 || word=="") return false;
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board[i].size(); ++j)
      {
        bool flg=find(i, j, word, board,0);
        if (flg == true) return flg;
      }
    }
    return false;
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input = { { 'a', 'b', 'c', 'd' }, { 'a', 'b', 't', 'r' } };
  string target = "cdrt";
  bool res = slu.exist(input, target);
  cout << res<<endl;
  system("pause");
}