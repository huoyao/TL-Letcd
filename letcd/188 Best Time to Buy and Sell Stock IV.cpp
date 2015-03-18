#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices) {
    int maxp = 0, total = 0,len=prices.size();
    if(len < 2 || k<1) return 0;
    if(k >= len / 2)
    {
      for(int i = 1;i < len;++i)
      {
        int dis = prices[i] - prices[i - 1];
        total += dis>0 ? dis : 0;
      }
      return total;
    }
    vector<int> buy(k,INT_MIN);  //rest money after kth buy for the ith stock
    vector<int> sell(k,0);       //rest monye after kth sell for the ith stock
    for(int i = 0;i < len;++i)
    {
      for(int j = k - 1;j >= 0;--j)
      {
        sell[j] = max(sell[j], buy[j] + prices[i]);
        buy[j] = max(buy[j], sell[j - 1] - prices[i]);
      }
    }
    return sell[k - 1];
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int target = 9;
  int res = slu.maxProfit(target,input);
  cout << res <<endl;
  system("pause");
  return 0;
}