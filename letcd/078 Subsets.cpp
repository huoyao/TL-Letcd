#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<int> > res;
  vector<int> rec;
  int len;
public:
  void getit(int cnt, int start, const int &k, const vector<int> &S)
  {
    if (cnt == k)
      res.push_back(rec);
    else
    {
      for (int i = start; i < len; ++i)
      {
        rec.push_back(S[i]);
        getit(cnt + 1, i + 1, k, S);
        rec.pop_back();
      }
    }
  }
  vector<vector<int> > subsets(vector<int> &S) {
    len = S.size();
    res.push_back(rec);
    if (len <= 0) return res;
    sort(S.begin(), S.end());
    for (int i = 1; i <= len; ++i)
    {
      getit(0, 0, i, S);
    }
    return res;
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