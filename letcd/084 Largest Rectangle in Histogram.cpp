#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    if (height.size() == 0) return 0;
    int res = INT_MIN;
    stack<int> st;
    for (int i = 0; i < height.size(); ++i)
    {
      if (st.empty() || height[i]>=height[st.top()]) st.push(i);
      else
      {
        while (!st.empty() && height[st.top()] > height[i])
        {
          int h = height[st.top()];
          st.pop();
          int width = st.empty() ? i : i - st.top()-1;
          res = max(res,width*h);
        }
        --i;
      }
    }
    while (!st.empty())
    {
      int h = height[st.top()];
      st.pop();
      int width = st.empty() ? height.size() : height.size() - st.top()-1;
      res = max(res, width*h);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 3, 6, 5, 7, 4, 8, 1, 0 };
  int res = slu.largestRectangleArea(input);
  cout << res<<endl;
  system("pause");
}
#endif
