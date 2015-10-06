#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string res="";
    int alen = a.length()-1, blen = b.length()-1,ex=0,all;
    char c;
    while (alen >= 0 || blen >= 0)
    {
      all = ex;
      if (blen >= 0)
        all += b[blen] - '0';
      if (alen>=0)
        all += a[alen] - '0';
      c = '0' + all % 2;
      res = c+ res;
      ex = all / 2;
      --alen;
      --blen;
    }
    if (ex == 1) res = '1' + res;
    return res;
  }
};

int main()
{
  Solution slu;
  string a = "111", b = "11";
  string res = slu.addBinary(a, b);
  cout << res<<endl;
  system("pause");
}
#endif
