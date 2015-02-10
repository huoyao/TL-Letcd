#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> res;
  vector<vector<int> > rec;
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty() || dict.empty()) return res;
    s = "*" + s;
    rec.resize(s.length());
    vector<bool> div(s.length(),false);
    div[0] = true;
    for (int i = 1; i < s.length(); ++i)
      for (int j = 0; j < i; ++j)
        if (div[j] && dict.count(s.substr(j + 1, i - j))){ rec[i].push_back(j); div[i] = true; }
    dfs(res,s,"",s.size()-1,rec);
    return res;
  }
  void dfs(const string &s, string str, int depth)
  {
    if (depth <= 0)
    {
      res.push_back(str.substr(0, str.length() - 1));
      return;
    }
    for (int i = 0; i < rec[depth].size(); ++i)
      dfs(s, s.substr(rec[depth][i] + 1, depth - rec[depth][i]) + " " + str, rec[depth][i]);
  }
};

int main()
{
  Solution slu;
  string s = "leetcode";
  unordered_set<string> dict = { "leet", "code", "det" };
  vector<string> res = slu.wordBreak(s, dict);
  for (auto &t : res)
    cout << t << endl;
  cout << endl;
  system("pause");
}