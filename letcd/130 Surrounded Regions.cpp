#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
  int width, length;
public:
  void solve(vector<vector<char> > &board) {
    width = board.size(),length=width?board[0].size():0;
    if (width == 0 || length==0)  return;
    for (int i = 0; i < length; ++i)
    {
      if (board[0][i] == 'O') bfsBoundary(board, 0, i);
      if (board[width - 1][i] == 'O') bfsBoundary(board, width - 1, i);
    }
    for (int i = 0; i < width; ++i)
    {
      if (board[i][0] == 'O') bfsBoundary(board, i, 0);
      if (board[i][length - 1] == 'O') bfsBoundary(board, i, length - 1);
    }
    for (int i = 0; i < width; ++i)
    {
      for (int j = 0; j < length; ++j)
      {
        if(board[i][j] == 'X') continue;
        else if (board[i][j] == 'O') board[i][j] = 'X';
        else board[i][j] = 'O';
      }
    }
  }
  void bfsBoundary(vector<vector<char> >& board, int w, int l)
  {
    deque<pair<int, int> > q;
    q.push_back(make_pair(w, l));
    board[w][l] = 'B';
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop_front();
      const int&x = cur.first, &y = cur.second;
      if(x - 1 >= 0 && board[x - 1][y] == 'O') {
        q.push_back(make_pair(x-1, y));
        board[x-1][y] = 'B';
      }
      if(y - 1 >= 0 && board[x][y-1] == 'O') {
        q.push_back(make_pair(x, y-1));
        board[x][y-1] = 'B';
      }
      if(x + 1 < width && board[x + 1][y] == 'O') {
        q.push_back(make_pair(x + 1, y));
        board[x + 1][y] = 'B';
      }
      if(y + 1 < length && board[x][y+1] == 'O') {
        q.push_back(make_pair(x, y+1));
        board[x][y+1] = 'B';
      }
    }
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input = { { 'x', 'x', 'x', 'x' }, { 'x', 'x', 'o', 'x' }, { 'x', 'o', 'o', 'x' }, { 'x', 'x', 'x', 'x' }};
  slu.solve(input);
  for (auto &t : input)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
