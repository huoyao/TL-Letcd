#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> res;
  vector<string> rec;
  int len;
public:
  vector<string> restoreIpAddresses(string s) {
    len = s.length();
    findIP(s,0);
    return res;
  }
  void findIP(const string &s, int idx)
  {
    if (rec.size() == 4)
    {
      string tmp = rec[0] + "." + rec[1] + "." + rec[2] + "." + rec[3];
      if (idx == len) res.push_back(tmp);
      return;
    }
    int val = 0;
    for (int i = 0; i < 3 && idx + i<len; ++i)
    {
      if (val == 0 && i>0) return; //mark
      val = val * 10 + s[idx + i] - '0';
      if (val>255) return;
      rec.push_back(s.substr(idx, i + 1));
      findIP(s, idx + i + 1);
      rec.pop_back();
    }
  }
};

int main()
{
  Solution slu;
  string input = "25525511135";
  vector<string> res = slu.restoreIpAddresses(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}