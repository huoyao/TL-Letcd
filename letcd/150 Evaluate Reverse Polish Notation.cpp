#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); ++i)
    {
      string str = tokens[i];
      if (str[0] >= '0' && str[0] <= '9' || str.length()>1) { st.push(stoi(str)); continue;}
      int b = st.top(); st.pop();
      int a = st.top(); st.pop();
      switch (str[0])
      {
      case '+':
        st.push(a + b); break;
      case'-':
        st.push(a - b); break;
      case '/':
        st.push(a / b); break;
      case '*':
        st.push(a*b); break;
      default:
        break;
      }
    }
    if (!st.empty()) return st.top();
    else return 0;
  }
};

int main()
{
  Solution slu;
  vector<string> input = { "1", "-3","+"};
  int res = slu.evalRPN(input);
  cout << res<< endl;
  system("pause");
}