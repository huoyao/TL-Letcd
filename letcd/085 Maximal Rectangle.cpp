#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    vector<int> ht(matrix[0].size()+1,0);
    int maxres = 0;
    bool needupdate = false;
    for (int i = 0; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
        if (matrix[i][j] == '1') { ++ht[j]; needupdate = true; }
        else ht[j] = 0;
      }
      if (needupdate) maxres = max(maxres, hist(ht));
    }
    return maxres;
  }
  int hist(const vector<int> &ht)
  {
    int res = 0;
    stack<int> st;
    for (int i = 0; i < ht.size();)
    {
      if (st.empty() || ht[st.top()] < ht[i]) st.push(i++);
      else
      {
        int idx = st.top();
        st.pop();
        res = max(res, (st.empty() ? i : i - st.top() - 1)*ht[idx]);
      }
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<vector<char> > input = { { '1', '0', '1', '0' }, { '0', '1', '1', '1' }, { '1', '1', '1', '1' } };
  int res = slu.maximalRectangle(input);
  cout << res<<endl;
  system("pause");
}