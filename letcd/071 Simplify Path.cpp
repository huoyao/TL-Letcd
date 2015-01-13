#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  struct st{
    string str;
    st *next, *pre;
    st(string val) :str(val), next(NULL), pre(NULL){}
  };
public:
  string simplifyPath(string path) {
    string res = "";
    int len = path.length();
    st *h = NULL, *pt = NULL;
    for (int i = 0; i < len;)
    {
      string tmp = "";
      while (path[i] == '/') ++i;
      if (i == len) break;
      while (path[i] != '/') tmp += path[i++];
      if (tmp == ".") continue;
      if (tmp == "..")
      {
        if (pt)
          pt = pt->pre;
        if (!pt) h = NULL;
      }
      else
      {
        st *newst = new st(tmp);
        if (!h) h = newst;
        if (!pt) pt = newst;
        else { pt->next = newst; newst->pre = pt; pt = newst; }
      }
    }
    if (!pt || !h) return "/";
    while (h != pt) { res += ("/" + h->str); h=h->next; }
    res += ("/"+h->str);
    return res;
  }
};

int main()
{
  Solution slu;
  string input = "/z//";
  string res = slu.simplifyPath(input);
  cout << res << endl;
  system("pause");
}