#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() <= 1) return 0;
    int ans = 0, last = -1;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(')
        st.push(i);
      else
      {
        if (st.empty())
          last = i;
        else
        {
          st.pop();
          if (st.empty())
            ans = max(ans, i - last);
          else
            ans = max(ans, i - st.top());   
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution slu;
  string vecnum = "()";
  int res = slu.longestValidParentheses(vecnum);
  cout << res << endl;
  system("pause");
}