#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> res;
    if (L.size() == 0) return res;
    int slen = S.length(), llen = L.size(), strlen = L[0].length();
    map<string, int> mapa, mapb;
    for (int i = 0; i < L.size(); ++i)
      mapa[L[i]]++;
    for (int i = 0; i <= slen - llen*strlen; ++i)
    {
      mapb.clear();
      int j = 0;
      for (; j < llen; ++j)
      {
        string tmp = S.substr(i+j*strlen,strlen);
        if (mapa.find(tmp) == mapa.end())
          break;
        mapb[tmp]++;
        if (mapb[tmp]>mapa[tmp])
          break;
      }
      if (j == llen) res.push_back(i);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  string vecnum ="abcdefg";
  vector<string> vecstr(3);
  vecstr[0] = "bc";
  vecstr[1] = "de";
  vecstr[2] = "fg";
  vector<int> res = slu.findSubstring(vecnum, vecstr);
  for (auto &t:res)
  cout << t << endl;
  system("pause");
}