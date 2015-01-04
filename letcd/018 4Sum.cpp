#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> >res;
    if (num.size() < 4) return res;
    sort(num.begin(),num.end());
    for (int i = 0; i < num.size() - 3; ++i)
    {
      if (i>0 && num[i] == num[i - 1]) continue;  //mark
      for (int j = i + 1; j < num.size() - 2; ++j)
      {
        if (j>i+1 && num[j] == num[j - 1]) continue;  //mark
        int remain = target - num[i] - num[j];
        int lidx = j + 1, ridx = num.size() - 1;
        while (lidx < ridx)
        {
          int sum = num[lidx] + num[ridx];
          if (sum == remain)
          {
            vector<int > vec = {num[i],num[j],num[lidx],num[ridx]};
            res.push_back(vec);
            while (lidx + 1 <= ridx && num[lidx + 1] == num[lidx]) ++lidx;
            while (ridx - 1 >= lidx && num[ridx - 1] == num[ridx]) --ridx;
            ++lidx;
          }
          else if (sum < remain) ++lidx;
          else --ridx;
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 1 ,0, - 1, 0, -2, 2 };
  int target = 0;
  vector<vector<int> > res = slu.fourSum(vecnum, target);
  for (auto &t:res)
    cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << endl;
  system("pause");
}