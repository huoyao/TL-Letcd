#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start.empty() || start.length() != end.length()) return 0;
    int level = 1, cnt = 1;
    queue<string> que;
    que.push(start);
    dict.erase(start);
    while (!que.empty())
    {
      string word = que.front();
      que.pop();
      --cnt;
      for (int i = 0; i < word.length(); ++i)
      {
        string tmp = word;
        for (int j = 'a'; j <= 'z'; ++j)
        {
          if (tmp[i] == j) continue;
          tmp[i] = j;
          if (tmp == end) return level + 1;
          if (dict.count(tmp)) { que.push(tmp); dict.erase(tmp); }
        }
      }
      if (cnt == 0){ cnt = que.size(); ++level; }
    }
    return 0;
  }
};

int main()
{
  Solution slu;
  string start = "hit", end = "cog";
  unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
  int res = slu.ladderLength(start, end, dict);
  cout << res << endl;
  system("pause");
}