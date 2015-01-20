#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) return 0;
    int profit = 0, minp = prices[0];
    for (int i = 0; i < prices.size(); i)
    {
      int idx = i+1;
      while (idx<prices.size() && prices[idx]>prices[idx-1]) ++idx;
      profit += prices[idx - 1] - minp;
      if (idx < prices.size()) minp = prices[idx];
      i = idx;
    }
    return profit;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 1, 4};
  int res = slu.maxProfit(input);
  cout << res<<endl;
  system("pause");
}