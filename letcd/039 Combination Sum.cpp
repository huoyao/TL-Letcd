#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combi(const vector<int> &cand, vector<vector<int> > &res, vector<int> record, int idx, int sum, const int &target)
{
  if (sum == target)
  {
    res.push_back(record);
    return;
  }
  for (int i = idx; i < cand.size(); ++i)
  {
    if (sum + cand[i]>target) break;
    record.push_back(cand[i]);
    combi(cand, res, record, i, sum + cand[i], target);
    record.pop_back();
    
  }
}

class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int>::iterator it = unique(candidates.begin(), candidates.end());
    candidates.erase(it, candidates.end());
    vector<vector<int> > res;
    vector<int> record;
    combi(candidates, res, record, 0, 0, target);
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 1,2, 7, 11, 15 };
  int target = 9;
  vector<vector<int> > res = slu.combinationSum(input, target);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}