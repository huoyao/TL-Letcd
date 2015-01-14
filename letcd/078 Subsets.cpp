#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getit(vector<vector<int> > &res, vector<int> &rec, int cnt, int start, const int n, const int &k,const vector<int> &S)
{
  if (cnt == k)
    res.push_back(rec);
  else
  {
    for (int i = start; i < n; ++i)
    {
      rec.push_back(S[i]);
      getit(res, rec, cnt + 1, i + 1, n, k,S);
      rec.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > vec;
    vector<int> tmp;
    vec.push_back(tmp);
    if (S.size()<=0) return vec;
    sort(S.begin(),S.end());
    for (int i = 1; i <= S.size(); ++i)
    {
      getit(vec, tmp, 0, 0, S.size(), i,S);
    }
    return vec;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2 };
  vector<vector<int> > res = slu.subsets(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}