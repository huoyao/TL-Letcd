#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > vecres;
    sort(num.begin(), num.end());
    int siz = num.size()-2;
    for (int i = 0; i < siz; ++i)  //mark
    {
      if (i>0 && num[i] == num[i - 1]) continue;
      int lidx = i + 1, ridx = siz+1,sumtmp;
      while (lidx < ridx)
      {
        sumtmp =num[i]+ num[lidx] + num[ridx];
        if (sumtmp == 0)
        {
          vecres.push_back({ num[i], num[lidx], num[ridx] });
          while (num[lidx + 1] == num[lidx] && lidx + 1 <= ridx) ++lidx;
          while (num[ridx - 1] == num[ridx] && ridx - 1 >= lidx) --ridx;
          ++lidx;
        }
        else if (sumtmp > 0) --ridx;
        else ++lidx;
      }
    }
    return vecres;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { -2, 0, 1, 1, 2 ,4,5,6,3,4,2,5,2,1};
  int cnt = 100;
  vector<vector<int> > res;
  while (cnt--)
   res = slu.threeSum(vecnum);
  for (int i = 0; i < res.size();++i)
    cout << res[i][0] << "  " << res[i][1] << "  " << res[i][2] << endl;
}
#endif
