#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  int res;
public:
  int totalNQueens(int n) {
    res = 0;
    vector<int> state(n, -1);
    find(state, 0);
    return res;
  }
  void find(vector<int> &state, const int idx)
  {
    if (idx == state.size())
      ++res;
    else
    {
      for (int col = 0; col < state.size(); ++col)
      {
        if (isOK(state, idx, col))
        {
          state[idx] = col;
          find(state, idx + 1);
          state[idx] = -1;
        }
      }
    }
  }
  bool isOK(vector<int> state, const int row, const int col)
  {
    for (int i = 0; i < row; ++i)
      if (state[i] == col || abs(row - i) == abs(col - state[i])) return false;
    return true;
  }
};

int main()
{
  Solution slu;
  int target = 4;
  int res = slu.totalNQueens(target);
  cout << res << endl;
  system("pause");
}