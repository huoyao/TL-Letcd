#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if (numRows <= 0) return res;
    for (int i = 1; i <= numRows; ++i)
    {
      vector<int> rec = {1};
      for (int j = 1; j < i - 1; ++j)
        rec.push_back(res[i-2][j-1]+res[i-2][j]);
      if (i != 1) rec.push_back(1);
      res.push_back(rec);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int target = 5;
  vector<vector<int> > res = slu.generate(target);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  cout << endl;
  system("pause");
}
#endif
