#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<int> > res;
public:
  vector<vector<int> > permute(vector<int> &num) {
    find(num,0);
    return res;
  }
  void find(vector<int> &num, int beg)
  {
    if (beg == num.size()-1)
    {
      res.push_back(num);
      return;
    }
    for (int i = beg; i < num.size(); ++i)
    {
      swap(num[beg], num[i]);
      find(num, beg + 1);
      swap(num[beg], num[i]);
    }
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 1,2 };
  vector<vector<int> > res = slu.permute(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
