#if 0
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string res = "";
    int len = path.length();
    stack<string> vecstr;
    int pos = 0,end_pos=0;
    while(pos<len)
    {
      end_pos=path.find_first_of("/", pos);
      if(end_pos == -1) end_pos = len;
      string tmp = path.substr(pos, end_pos - pos);
      pos = end_pos+1;
      if (tmp == ".."){
        if (!vecstr.empty()) vecstr.pop();
      }
      else if(tmp!="." && tmp!="")
        vecstr.push(tmp);
    }
    if (vecstr.empty()) return "/";
    while (!vecstr.empty()) {
      res = "/" + vecstr.top() + res;
      vecstr.pop();
    }   
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
#endif
