#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    char ss[2005];
    ss[0] = '&';
    int cnt = 1;
    for (int i = 0; i < s.length();++i)
    {
      ss[cnt++] = '#';
      ss[cnt++] = s[i];
    }
    ss[cnt++] = '#';
    ss[cnt] = '\0';
    vector<int> vecp(cnt+1,0);
    int resid=0, mx = 0, maxid=0;
    for (int i = 1; i < cnt; ++i)
    {
      if (mx>i)
        vecp[i] = min(vecp[2 * maxid - i], mx - i);
      else
        vecp[i] = 1;
      while (ss[i + vecp[i]] == ss[i - vecp[i]]) ++vecp[i];
      if (vecp[i] + i > mx){
        mx = vecp[i] + i; 
        maxid = i;
      }
      if (vecp[resid] < vecp[i])resid = i;
    }
    int len = vecp[resid];
    return s.substr((resid>>1)-(len>>1),len-1);
  }
};

int main()
{
  Solution slu;
  string s = "abbfafdlsajdfadsafdsafdsafdsafdsafdsafdsafdsafdsafdsjdfjkdjfkdksdkjfdjfkdjksfdkfjkdjfkrueiwtunzngajgutijgkl;jsdagkjitreiwptgsd;jgfsdio";
  string st = slu.longestPalindrome(s);
  cout << st<< endl;
  system("pause");
}
#endif
