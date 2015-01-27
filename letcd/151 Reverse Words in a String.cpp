#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    int len = s.length(),i=0,j=len-1,idx=0,cnt=0,start,end;
    bool first = true;
    if (s.empty()) return;
    while (i < j) swap(s[i++],s[j--]);
    while (idx<len)
    {
      while (s[idx]==' ') ++idx;
      start = i= idx;
      if (idx == len) break;
      while (idx<len && s[idx]!= ' ') ++idx;
      end = j = idx - 1;
      while (i < j) swap(s[i++],s[j--]);
      if (!first) s[cnt++] = ' ';
      first = false;
      while (start <= end) s[cnt++] = s[start++];
    }
    s.erase(cnt,len-cnt);
  }
};

int main()
{
  Solution slu;
  string str = "k";
  int target = 9;
  slu.reverseWords(str);
  cout << str << endl;
  system("pause");
}