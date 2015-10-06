#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<int> > res;
  vector<int> rec;
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(),S.end());
    subStrII(0,S);
    return res;
  }
  void subStrII(int idx, const vector<int> &S)
  {
    res.push_back(rec);
    for (int i = idx; i < S.size(); ++i)
    {
      if (i != idx && S[i] == S[i - 1]) continue;
      rec.push_back(S[i]);
      subStrII(i + 1, S);
      rec.pop_back();
    }
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
#endif
