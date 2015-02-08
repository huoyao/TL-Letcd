#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> res;
public:
  vector<string> generateParenthesis(int n) {
    getres(n,n,"",vecstr);
    return vecstr;
  }
  void getres(int l, int r, string s)
  {
    if (l == 0 && r == 0)
    {
      res.push_back(s);
      return;
    }
    if (l > 0) getres(l - 1, r, s + "(");
    if (l<r && r>0) getres(l, r - 1, s + ")");
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