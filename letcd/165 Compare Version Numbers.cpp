#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int len1 = version1.length(), len2 = version2.length(),beg1=0,beg2=0,end1=0,end2=0;
    while (beg1 < len1 && beg2 < len2)
    {
      int a = geti(beg1, version1, len1,end1), b = geti(beg2,version2,len2,end2);
      if (a < b) return -1;
      if (a > b) return 1;
      beg1 = ++end1;
      beg2 = ++end2;
    }
    int a = geti(beg1, version1, len1, end1);
    while (a >= 0){ beg1 = ++end1; if (a>0) return 1; a = geti(beg1, version1, len1, end1); }
    int b = geti(beg2, version2, len2, end2);
    while (b >= 0){ beg2 = ++end2; if (b>0) return -1; b = geti(beg2, version2, len2, end2); }
    if (beg1 < len1) return -1;
    if (beg2 < len2) return 1;
    return 0;
  }
  int geti(const int &beg, string str, const int &len, int &end)
  {
    if (beg >= len) return -1;
    end = beg;
    while (end<len && str[end] != '.') ++end;
    return stoi(str.substr(beg, end));
  }
};

int main()
{
  Solution slu;
  string input = "1.2.1", target = "1.2";
  int res = slu.compareVersion(input, target);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
