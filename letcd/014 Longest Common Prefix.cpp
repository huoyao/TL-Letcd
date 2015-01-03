#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";  //mark
    string comm = strs[0];
    for (int i = 0; i < strs.size(); ++i)
    {
      if (strs[i].find(comm) == 0) continue;
      int mxidx = min(comm.length(),strs[i].length()),idx=0;
      while (idx<mxidx && comm[idx] == strs[i][idx]) ++idx;
      comm = comm.substr(0,idx);
    }
    return comm;
  }
};

int main()
{
  Solution slu;
  vector<string> vecnum = { "line","lin","linett","l" };
  string res = slu.longestCommonPrefix(vecnum);
  cout << res << endl;
  system("pause");
}