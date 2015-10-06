#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<int> > res;
  vector<int> rec;
  int len, kk;
public:
  vector<vector<int> > combine(int n, int k) {
    len = n, kk = k;
    if (len <= 0 || kk <= 0) return res;
    getit(0,1);
    return res;
  }
  void getit(int cnt, int start)
  {
    if (cnt == kk)
      res.push_back(rec);
    else
    {
      for (int i = start; i <= len; ++i)
      {
        rec.push_back(i);
        getit(cnt + 1, i + 1);
        rec.pop_back();
      }
    }
  }
};

int main()
{
  Solution slu;
  int input = 4;
  int target = 2;
  vector<vector<int> > res = slu.combine(input, target);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
