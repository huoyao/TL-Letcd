#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > vecres;
    sort(num.begin(),num.end());
    int cnt = 0;
    for (int i = 0; i < (int)(num.size()-2); ++i)  //mark
    {
      if (i>0 && num[i] == num[i - 1]) continue;
      int lidx = i + 1, ridx = num.size() - 1;
      int sum = -num[i],sumtmp;
      while (lidx < ridx)
      {
        sumtmp = num[lidx] + num[ridx];
        if (sumtmp == sum)
        {
          vector<int> vectmp;
          vectmp.push_back(num[i]);
          vectmp.push_back(num[lidx]);
          vectmp.push_back(num[ridx]);
          vecres.push_back(vectmp);
          while (num[lidx + 1] == num[lidx] && lidx + 1 <= ridx) ++lidx;
          while (num[ridx - 1] == num[ridx] && ridx - 1 >= lidx) --ridx;
          ++lidx;
        }
        else if (sumtmp > sum)
          --ridx;
        else
          ++lidx;
      }
    }
    return vecres;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { -2, 0, 1, 1, 2 };
  vector<vector<int> > res = slu.threeSum(vecnum);
  for (int i = 0; i < res.size();++i)
    cout << res[i][0] << "  " << res[i][1] << "  " << res[i][2] << endl;
  system("pause");
}