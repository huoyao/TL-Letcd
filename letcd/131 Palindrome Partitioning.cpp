#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void dfs(string s, vector<string> rec, vector<vector<string> > &res)
{
  if (s.length() == 0)
  {
    res.push_back(rec);
    return;
  }
  for (int i = 0; i < s.length(); ++i)
  {
    int beg = 0, end = i;
    while (beg < end)
    {
      if (s[beg] != s[end]) break;
      ++beg;
      --end;
    }
    if (beg >= end)
    {
      rec.push_back(s.substr(0,i+1));
      dfs(s.substr(i+1),rec,res);
      rec.pop_back();
    }
  }
}

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string> > res;
    if (s.length() == 0) return res;
    vector<string> rec;
    dfs(s,rec,res);
    return res;
  }
};

int main()
{
  Solution slu;
  string input="aab";
  int target = 9;
  vector<vector<string> > res = slu.partition(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}