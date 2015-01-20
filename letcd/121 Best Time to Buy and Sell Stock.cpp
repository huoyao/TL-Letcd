#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) return 0;
    int profit = 0, minp = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
      profit = prices[i] - minp>profit ? prices[i] - minp : profit;
      minp = min(minp,prices[i]);
    }
    return profit;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int res = slu.maxProfit(input);
  cout << res<<endl;
  system("pause");
}