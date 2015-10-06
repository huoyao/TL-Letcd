#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maximumGap(vector<int> &num) {
    if (num.size() < 2) return 0;
    int len = num.size(),dst,mine=INT_MAX,maxe=INT_MIN,res=INT_MIN;
    for (int i = 0; i < len; ++i) { mine = min(mine, num[i]); maxe = max(maxe,num[i]); }
    dst = (maxe - mine+len-2) / (len - 1);
    vector<int> bukmin(len - 1, INT_MAX), bukmax(len-1,INT_MIN);
    for (int i = 0; i < len; ++i)
    {
      if (num[i] == mine || num[i] == maxe) continue;
      int idx = (num[i] - mine)/dst;
      bukmin[idx] = min(bukmin[idx],num[i]);
      bukmax[idx] = max(bukmax[idx],num[i]);
    }
    for (int i = 0; i < len - 1; ++i)
    {
      if (bukmin[i] == INT_MAX && bukmax[i] == INT_MIN) continue;
      res = max(res,bukmin[i]-mine);
      mine = bukmax[i];
    }
    res = max(res,maxe-mine);
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 0, 1, 15 };
  int res = slu.maximumGap(input);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
