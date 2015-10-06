#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    int len = s.length(),idx=0;
    stack<char> st;
    while (idx < len)
    {
      char c = s[idx];
      switch (c)
      {
      case '(':
      case '[':
      case '{':
        st.push(c);
        break;
      case ')':
        if (st.empty() || st.top() != '(') return false;  //mark for "st.empty()"
        st.pop();
        break;
      case ']':
        if (st.empty() || st.top() != '[') return false;
        st.pop();
        break;
      case '}':
        if (st.empty() || st.top() != '{') return false;
        st.pop();
        break;
      default:
        break;
      }
      ++idx;
    }
    return st.empty()?true:false;  //mark
  }
};

int main()
{
  Solution slu;
  string str = "()()[][]";
  int target = 9;
  bool res = slu.isValid(str);
  cout << res << endl;
  system("pause");
}
#endif
