#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void decode(string &s, const int idx, const int ctt, const int &len, int &cnt)
{
  if (idx + ctt >= len)
  {
    if (idx + ctt == len) ++ cnt;
    return;
  }
  int tag = 0;
  if (ctt == 1) tag = s[idx] - '0';
  else
    tag = (s[idx] - '0') * 10 + s[idx + 1] - '0';
  if (tag<1 || tag>26) return;
  decode(s, idx+ctt, 1, len, cnt);
  decode(s,idx+ctt,2,len,cnt);
}

class Solution {
public:
  int numDecodings(string s) {
    int cnt = 0;
    if (s.length() == 0) return cnt;
    decode(s,0,1,s.length(),cnt);
    decode(s,0,2,s.length(),cnt);
    return cnt;
  }
};

int main()
{
  Solution slu;
  string input = "1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
  int res = slu.numDecodings(input);
  cout << res<<endl;
  system("pause");
}