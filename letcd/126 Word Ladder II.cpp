#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
  vector<vector<string> > res;
public:
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    if (start.empty() || start.length() != end.length()) return res;
    unordered_map<string, vector<string> > preword;
    vector<unordered_set<string> > rec(2);
    dict.insert(end);
    for (auto it = dict.begin(); it != dict.end(); ++it)
      preword[*it] = vector<string>();
    int crr = 0, pre = 1;
    bool hasfind = false;
    rec[0].insert(start);
    while (!rec[crr].empty() && !hasfind)
    {
      crr = !crr;
      pre = !pre;
      for(auto it = rec[pre].begin();it != rec[pre].end();++it)
        dict.erase(*it);
      rec[crr].clear();
      for (auto it = rec[pre].begin(); it != rec[pre].end(); ++it)
      {
        string word = *it;
        for (int i = 0; i < word.size(); ++i)
        {
          string tmp = word;
          for (int j = 'a'; j <= 'z'; ++j)
          {
            if (tmp[i] == j) continue;
            tmp[i] = j;
            if (dict.count(tmp))
            {
              preword[tmp].push_back(word);
              rec[crr].insert(tmp);
              if (tmp == end) hasfind = true;
            }
          }
        }
      }
    }
    if (!hasfind) return res;
    vector<string> path = {end};
    build(preword,path,end);
    return res;
  }
  void build(unordered_map<string, vector<string> > &preword, vector<string> &path, const string &end)
  {
    if (preword[end].size() == 0)
    {
      vector<string> tmp = path;
      reverse(tmp.begin(), tmp.end());
      if(res.size() && tmp.size() < res.back().size())
        res.clear();
      res.push_back(tmp);
      return;
    }
    for (auto it = preword[end].begin(); it != preword[end].end(); ++it)
    {
      path.push_back(*it);
      build(preword, path, *it);
      path.pop_back();
    }
  }
};

int main()
{
  Solution slu;
  string start = "hit", end = "cog";
  unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
  vector<vector<string> > res = slu.findLadders(start, end, dict);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
