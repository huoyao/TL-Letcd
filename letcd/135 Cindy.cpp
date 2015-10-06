#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    if (ratings.size() == 0) return 0;
    int cindynum = 1;
    vector<int> cindy(ratings.size(),1);
    for (int i = 1; i < ratings.size(); ++i)
    {
      if (ratings[i]>ratings[i - 1])
        cindy[i] = max(++cindynum, cindy[i]);
      else
        cindynum = 1;
    }
    cindynum = 1;
    for (int i = ratings.size() - 2; i >= 0; --i)
    {
      if (ratings[i] > ratings[i + 1])
        cindy[i] = max(++cindynum, cindy[i]);
      else
        cindynum = 1;
    }
    cindynum = 0;
    for (int i = 0; i < cindy.size(); ++i)
      cindynum += cindy[i];
    return cindynum;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 3,2, 7, 11, 15 };
  int res = slu.candy(input);
  cout << res<<endl;
  system("pause");
}
#endif
