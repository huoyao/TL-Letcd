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
      while (i < len && path[i] == '/') ++i;
      if (i == len) break;
      while (i < len && path[i] != '/') tmp += path[i++];
      if (tmp == ".") continue;
      if (tmp == "..")
      {
        if (pt){
          st *tmp = pt->pre;
          delete(pt);
          pt = tmp;
        }
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
    st *ptr = h;
    while (h != pt) { res += ("/" + h->str); h = h->next; delete(ptr); ptr = h; }
    res += ("/" + h->str);
    delete(ptr);
    return res;
  }
};

int main()
{
  Solution slu;
  string input = "/.";
  string res = slu.simplifyPath(input);
  cout << res;
  system("pause");
}