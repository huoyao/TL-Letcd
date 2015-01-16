#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subStrII(int idx, vector<vector<int> > &res, vector<int> &rec, const vector<int> &S)
{
  res.push_back(rec);
  for (int i = idx; i < S.size(); ++i)
  {
    if (i != idx && S[i] == S[i - 1]) continue;
    rec.push_back(S[i]);
    subStrII(i+1,res,rec,S);
    rec.pop_back();
  }
}

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > res;
    vector<int> rec;
    sort(S.begin(),S.end());
    subStrII(0,res,rec,S);
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 1, 2, 2};
  vector<vector<int> > res = slu.subsetsWithDup(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}