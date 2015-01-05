#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void getres(int l,int r,string s,vector<string> &res)
{
  if (l == 0 && r == 0)
  {
    res.push_back(s);
    return;
  }
  if (l > 0)
    getres(l-1,r,s+"(",res);
  if (l<r && r>0)
    getres(l,r-1,s+")",res);
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    int l = n, r = n;
    vector<string> vecstr;
    string s;
    getres(l,r,s,vecstr);
    return vecstr;
  }
};

int main()
{
  Solution slu;
  int target = 3;
  vector<string> res = slu.generateParenthesis(target);
  for (auto &t:res)
  cout << t << "  ";
  system("pause");
}