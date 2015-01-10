#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  int res;
  int allone;
public:
  int totalNQueens(int n) {
    res = 0;
    allone = (1 << n) - 1;
    vector<string> cur(n, string(n, '.'));
    find(0, 0, 0, cur, 0);
    return res;
  }
  void find(const int row, const int ld, const int rd, vector<string> &cur, const int idx)
  {
    int pos, p;
    if (row == allone)
      ++res;
    else
    {
      pos = allone & (~(row | ld | rd));
      while (pos)
      {
        p = (~pos + 1) & pos;
        pos = pos - p;
        setQ(cur, p, idx, 'Q');
        find((row | p), (ld | p) << 1, (rd | p) >> 1, cur, idx + 1);
        setQ(cur, p, idx, '.');
      }
    }
  }
  void setQ(vector<string> &cur, int p, const int idx, char c)
  {
    int col = 0;
    while (!(p & 1))
    {
      p >>= 1;
      ++col;
    }
    cur[idx][col] = c;
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