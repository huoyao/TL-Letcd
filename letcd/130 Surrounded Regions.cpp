#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
  int m, n;
public:
  void dfs(vector<vector<char>> &board, int x, int y, vector<vector<bool> > &used)
  {
    queue<int> qx, qy;
    qx.push(x);
    qy.push(y);
    while (!qx.empty())
    {
      int t = qx.front(), k = qy.front();
      qx.pop();
      qy.pop();
      if (board[t][k] == 'X' || board[t][k] == 'U') continue;
      board[t][k] = 'U';
      used[t][k] = true;
      if (t > 0 && !used[t - 1][k]) { qx.push(t - 1); qy.push(k); };
      if (t<m - 1 && !used[t + 1][k]) { qx.push(t + 1); qy.push(k); };
      if (k>0 && !used[t][k-1]) { qx.push(t); qy.push(k-1); };
      if (k<n - 1 && !used[t][k+1]) { qx.push(t); qy.push(k+1); };
    }
  }
  void solve(vector<vector<char>> &board) {
    m = board.size();
    n = (m!=0 ? board[0].size() : 0);
    if (m == 0 || n == 0) return;
    vector<vector<bool> > used(m,vector<bool>(n,false));
    for (int i = 0; i < n; ++i)
    {
      dfs(board,0,i,used);
      dfs(board,m-1,i,used);
    }
    for (int i = 1; i < m-1; ++i)
    {
      dfs(board,i,0,used);
      dfs(board,i,n-1,used);
    }
    for (int i = 0; i < m; ++i)
       for (int j = 0; j < n; ++j)
         board[i][j] = board[i][j] == 'U' ? 'O' : 'X';
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