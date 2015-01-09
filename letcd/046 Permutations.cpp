#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(const vector<int> &num,vector<int> &rec,vector<bool> &notuse,vector<vector<int> > &res)
{
  if (rec.size() == num.size())
  {
    res.push_back(rec);
    return;
  }
  for (int i = 0; i < num.size(); ++i)
  {
    if (i != 0 && num[i] == num[i - 1] && notuse[i-1]) continue;
    if (!notuse[i]) continue;
    rec.push_back(num[i]);
    notuse[i] = false;
    find(num,rec,notuse,res);
    rec.pop_back();
    notuse[i] = true;
  }
}

class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<int> record;
    vector<vector<int> > res;
    if (num.size() <= 1) { res.push_back(num); return res; }
    sort(num.begin(), num.end());
    vector<bool> notused(num.size(),true);
    find(num,record,notused,res);
    return res;
  } 
};

int main()
{
  Solution slu;
  vector<int> input = { 1,1 };
  vector<vector<int> > res = slu.permute(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}