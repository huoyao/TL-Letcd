#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  int res = 0, allone;
public:
  int totalNQueens(int n) {
    allone = (1 << n) - 1;
    find(0, 0, 0, 0);
    return res;
  }
  void find(const int row, const int ld, const int rd, const int idx)
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
        find((row | p), (ld | p) << 1, (rd | p) >> 1, idx + 1);
      }
    }
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
#endif
