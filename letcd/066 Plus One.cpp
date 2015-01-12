#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int len = digits.size() - 1, ex = 1,all,a,b;
    vector<int> res;
    for (int i = len; i >=0; --i)
    {
      all = ex + digits[i];
      res.push_back( all % 10);
      ex = all / 10;
      if (ex==0)
      {
        while ((--i) >= 0) res.push_back(digits[i]);
        break;
      }
    }
    if (ex) res.push_back(ex);
    a = 0;
    b = res.size()-1;
    while (a < b) { swap(res[a], res[b]); ++a; --b;}
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 9, 9, 9, 7 };
  vector<int> res = slu.plusOne(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}