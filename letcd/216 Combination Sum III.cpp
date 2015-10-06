#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void combi(vector<int> &rec,int k,int sum,int id,int n)
  {
    if(k == 0 && sum == n) res.push_back(rec);
    if(k == 0) return;
    for(size_t i = id;i <= 9;++i)
    {
      sum += i;
      if(sum > n) return;
      rec.push_back(i);
      combi(rec, k - 1, sum, i + 1, n);
      rec.pop_back();
      sum -= i;
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> rec;
    combi(rec, k,0,1, n);
    return res;
  }
private:
  vector<vector<int>> res;
};

int main()
{
  Solution slu;
 int input = 3;
  int target = 9;
  vector<vector<int>> res = slu.combinationSum3(input, target);
  for(auto &t : res)
  {
    for(auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
  return 0;
}
#endif
