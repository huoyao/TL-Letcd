#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
private:
  vector<vector<int> > res;
  vector<int> rec;
  vector<bool> notuse;
  int len;
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    len = num.size();
    notuse = vector<bool>(len,true);
    if (len <= 1) { res.push_back(num); return res; }
    sort(num.begin(), num.end());
    find(num,0);
    return res;
  }
  void find(vector<int> num, int beg)
  {
    if (beg >= num.size())
    {
      res.push_back(num);
      return;
    }
    unordered_set<int> diff;
    for (int i = beg; i < num.size(); ++i)
    {
      if (diff.count(num[i])) continue;
      else diff.insert(num[i]);
      swap(num[beg], num[i]);
      find(num, beg + 1);
      swap(num[beg], num[i]);
    }
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 0, 1,0, 1};
  vector<vector<int> > res = slu.permuteUnique(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
