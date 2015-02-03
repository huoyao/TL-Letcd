#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <iterator>
using namespace std;

void addp(pair<int, int> &par1, pair<int, int> &par2, vector<vector<int> > &res, vector<int> &num)
{
  int &a1 = par1.first, &a2 = par1.second, &b1 = par2.first, &b2 = par2.second;
  if (b1<=a2 || b2==a1 || a1 == b1 || a2 == b2 ) return;
  if (res.size() == 0) res.push_back({ num[a1], num[a2], num[b1], num[b2] });
  vector<int> vec = res.back(), vec1 = { num[a1], num[a2], num[b1], num[b2] };
  if (vec==vec1) return;
  res.push_back(vec1);
}

bool chk(vector<int> &num,vector<pair<int, int> > &vecp, const int &i)
{
  return i && num[vecp[i].first] == num[vecp[i - 1].first] && num[vecp[i].second] == num[vecp[i - 1].second];
}

class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> >res;
    if (num.size() < 4) return res;
    unordered_map<int, vector<pair<int, int> > > mapsum;
    vector<int> vecsum;
    int sum2,sum4;
    sort(num.begin(),num.end());
    for (int i = 0; i < num.size()-1; ++i)
    {
      for (int j = i + 1; j < num.size(); ++j)
      {
        sum2 = num[i] + num[j];
        if (mapsum.count(sum2)) mapsum[sum2].push_back(pair<int, int>(i, j));
        else { mapsum[sum2] = { pair<int, int>(i, j) }; vecsum.push_back(sum2); };
      }
    }
    sort(vecsum.begin(),vecsum.end());
    int lidx = 0, ridx = vecsum.size() - 1;
    while (lidx<ridx)
    {
      sum4 = vecsum[lidx] + vecsum[ridx];
      if (sum4 > target) { --ridx; continue; }
      else if (sum4 < target) { ++lidx; continue; }
      else
      {
        vector<pair<int, int> > &vecpl = mapsum[vecsum[lidx]];
        for (int i = 0; i < vecpl.size(); ++i)
        {
          if (chk(num,vecpl, i)) continue;
          vector<pair<int, int> > &vecpr = mapsum[vecsum[ridx]];
          for (int j = 0; j < vecpr.size(); ++j)
            addp(vecpl[i], vecpr[j], res, num);
        }
        ++lidx;
        --ridx;
      }
    }
    if (lidx>ridx || 2 * vecsum[lidx] != target) return res;
    vector<pair<int, int> > &vecpl = mapsum[vecsum[lidx]];
    for (int i = 0; i < vecpl.size() - 1; ++i)
    {
      if (chk(num,vecpl,i)) continue;
      for (int j = i + 1; j <vecpl.size(); ++j)
        addp(vecpl[i], vecpl[j], res, num);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4, -5, 5, 4, -3, 0, 0, 4, -2, 4 };
  int target = 4;
  vector<vector<int> > res = slu.fourSum(vecnum, target);
  for (auto &t:res)
    cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << endl;
}