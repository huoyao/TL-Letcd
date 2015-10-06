#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> res;
    int slen = S.length(), llen = L.size(), strlen = L[0].length();
    if (llen == 0 || slen==0) return res;
    unordered_map<string, int> mapa;
    for (int i = 0; i < L.size(); ++i)
      ++mapa[L[i]];
    for (int i = 0; i < strlen; ++i)
    {
      int left = i, cnt = 0;
      unordered_map<string, int> mapb;
      for (int j = i; j <= slen - strlen; j+=strlen)
      {
        string str = S.substr(j, strlen);
        if (mapa.count(str))
        {
          ++mapb[str];
          if (mapb[str] <= mapa[str])
            ++cnt;
          else
          {
            while (mapb[str] > mapa[str])
            {
              string strbak = S.substr(left,strlen);
              --mapb[strbak];
              if (mapb[strbak] < mapa[strbak]) --cnt;
              left += strlen;
            }
          }
          if (cnt == llen)
          {
            res.push_back(left);
            --mapb[S.substr(left, strlen)];
            --cnt;
            left += strlen;
          }
        }
        else
        {
          mapb.clear();
          cnt = 0;
          left = j+strlen;
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution slu;
  string vecnum = "abcdefg";
  vector<string> vecstr(3);
  vecstr[0] = "bc";
  vecstr[1] = "de";
  vecstr[2] = "fg";
  vector<int> res = slu.findSubstring(vecnum, vecstr);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}
#endif
