#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0, len = prices.size();
    if (len < 2) return profit;
    vector<int> profit_l(len, 0), profit_r(len,0);
    int minp = prices[0],maxp=prices[len-1];
    for (int i = 1; i < len; ++i)
    {
      profit_l[i] = min(prices[i] - minp,profit_l[i - 1]);
      minp = min(minp,prices[i]);
    }
    for (int i = len - 2; i >= 0; --i)
    {
      profit_r[i] =max(maxp - prices[i],profit_r[i+1]);
      maxp = max(prices[i],maxp);
    }
    for (int i = 0; i < len; ++i)
      profit = max(profit,profit_l[i]+profit_r[i]);
    return profit;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 1, 15 };
  int res = slu.maxProfit(input);
  cout << res<<endl;
  system("pause");
}