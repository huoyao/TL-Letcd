#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string res = "";
    int len = path.length();
    vector<string> vecstr;
    for (int i = 0; i < len;)
    {
      string tmp = "";
      while (i < len && path[i] == '/') ++i;
      if (i == len) break;
      while (i < len && path[i] != '/') tmp += path[i++];
      if (tmp == ".") continue;
      if (tmp == ".."){
        if (!vecstr.empty()) vecstr.pop_back();
      }
      else
        vecstr.push_back(tmp);
    }
    if (vecstr.empty()) return "/";
    for (int i = 0; i < vecstr.size(); ++i)
      res += ("/" + vecstr[i]);
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