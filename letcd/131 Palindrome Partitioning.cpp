#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  vector<vector<string> > res;
  vector<string> rec;
  vector<vector<int> > map_pali;
public:
  vector<vector<string>> partition(string s) {
    int n = s.length();
    if (s.length() == 0) return res;
    vector<vector<bool> > map = vector<vector<bool> >(n, vector<bool>(n, false));
    map_pali.resize(n);
    for (int i = n - 1; i >= 0; --i)
    {
      for (int j = i; j < n; ++j)
      {
        map[i][j] = s[i] == s[j] && (j - i < 2 || map[i + 1][j - 1]);
        if (map[i][j]) map_pali[i].push_back(j);
      }
    }
    dfs(s,0);
    return res;
  }
  void dfs(string s, int end)
  {
    if (s.length() == end)
    {
      res.push_back(rec);
      return;
    }
    for (int i = 0; i < map_pali[end].size(); ++i)
    {
      int endidx=map_pali[end][i]+1;
      if (endidx<s.length() && map_pali[endidx].size() == 0) continue;
      rec.push_back(s.substr(end,endidx-end));
      dfs(s,endidx);
      rec.pop_back();
    }
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