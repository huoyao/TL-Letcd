#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int m = matrix.size(), n = matrix.size()?matrix[0].size():0,cnt=0;   //mark
    int minelem = min(m, n),id = minelem / 2, round1 = n - 1, round2 = m - 1, i = 0;
    bool moreline = false;
    vector<int> res(m*n);
    if (minelem % 2) moreline = true;
    for (; i < id; ++i)
    {
      int idx1 = i, idx2 = i;
      while (idx1 < round1) res[cnt++]=matrix[i][idx1++];
      while (idx2 < round2) res[cnt++]=matrix[idx2++][idx1];
      while (idx1 > i) res[cnt++]=matrix[idx2][idx1--];
      while (idx2 > i) res[cnt++]=matrix[idx2--][idx1];
      --round1;
      --round2;
    }
    if (!moreline) return res;
    if (minelem == m)
      for (int j = i; j <= round1; ++j) res[cnt++]=matrix[i][j];
    else
      for (int j = i; j <= round2; ++j) res[cnt++]=matrix[j][i];
    return res;
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
  vector<int> res = slu.spiralOrder(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}
#endif
