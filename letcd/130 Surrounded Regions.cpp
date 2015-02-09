#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
  int width, length;
public:
  void bfsBoundary(vector<vector<char> >& board, int w, int l)
  {
    deque<pair<int, int> > q;
    q.push_back(make_pair(w, l));
    board[w][l] = 'B';
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop_front();
      pair<int, int> adjs[4] = { { cur.first - 1, cur.second },
      { cur.first + 1, cur.second },
      { cur.first, cur.second - 1 },
      { cur.first, cur.second + 1 } };
      for (int i = 0; i < 4; ++i)
      {
        int &adjW = adjs[i].first;
        int &adjL = adjs[i].second;
        if (adjW >= 0 && adjW < width && adjL >= 0 && adjL < length
          && board[adjW][adjL] == 'O') {
          q.push_back(make_pair(adjW, adjL));
          board[adjW][adjL] = 'B';
        }
      }
    }
  }

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
        if (board[i][j] == 'O') board[i][j] = 'X';
        else if (board[i][j] == 'B') board[i][j] = 'O';
      }
    }
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input = { { 'x', 'x', 'x', 'x' }, { 'x', 'x', 'o', 'x' }, { 'x', 'o', 'o', 'x' }, { 'x', 'x', 'x', 'x' }};
  int target = 9;
  slu.solve(input);
  for (auto &t : input)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}