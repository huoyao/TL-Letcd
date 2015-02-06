#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int ans = 0, len = s.length();
    vector<int> longest(len,0);
    if (len <= 1) return 0;
    for (int i = 0; i < len; ++i)
    {
      int idx = i - longest[i - 1] - 1;
      if (s[i] == ')' && idx >= 0 && s[idx] == '(')
        longest[i] = longest[i-1] + 2 + (idx - 1 >= 0 ? longest[idx - 1] : 0);
      ans = max(ans,longest[i]);
    }
    return ans;
  }
};

int main()
{
  Solution slu;
  string vecnum = "()(())";
  int res = slu.longestValidParentheses(vecnum);
  cout << res << endl;
  system("pause");
}