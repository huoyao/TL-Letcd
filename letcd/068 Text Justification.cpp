#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void inst(const int &L, const int &strlen, const int &start, const int &end, const vector<string> &words, vector<string> &res, bool islast)
{
  string str = "";
  int spacenum = L - strlen, wordnum = end - start - 1 == 0 ? 1 : end - start - 1;
  int everyspace = spacenum / wordnum;
  int extaspace = wordnum == 1 ? 0 : spacenum % wordnum;
  string tmp(everyspace, ' ');
  str += words[start];
  int i = start + 1;
  for (; i < end; ++i)
  {
    str += ' ';
    if (!islast)
    {
      str += tmp;
      if (extaspace>0) str += ' ';
      --extaspace;
    }
    str += words[i];
  }
  if (islast)
  {
    string lst(spacenum,' ');
    str += lst;
    res.push_back(str);
    return;
  }
  if (i == start + 1) str += tmp;
  res.push_back(str);
}

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    int len = words.size(), strlen = -1, start, end;
    vector<string> res;
    bool islast = false;
    for (int idx = 0; idx < len; ++idx)
    {
      strlen = -1;
      start = idx;
      while (idx < len && strlen <= L) strlen += words[idx++].length() + 1;
      if (strlen <= L)
        end = idx;
      else
      {
        end = idx - 1;
        idx -= 2;
        strlen -= (words[idx + 1].length() + 1);
      }
      if (end == len) islast = true;
      inst(L, strlen, start, end, words, res, islast);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<string> input = { "This", "is", "a", "exmple", "let's", "go!" };
  int target = 9;
  vector<string> res = slu.fullJustify(input, target);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}