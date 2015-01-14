#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getit(vector<vector<int> > &res, vector<int> &rec, int cnt,int start, const int &n,const int &k)
{
  if (cnt == k)
    res.push_back(rec);
  else
  {
    for (int i =start; i <= n; ++i)
    {
      rec.push_back(i);
      getit(res,rec,cnt+1,i+1,n,k);
      rec.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > vec;
    if (k <= 0 || n <= 0) return vec;
    vector<int> rec;
    vector<bool> used(n+1, false);
    getit(vec, rec, 0,1, n,k);
    return vec;
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