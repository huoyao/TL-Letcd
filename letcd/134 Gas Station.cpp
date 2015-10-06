#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) return -1;
    int all = 0, tempsum = 0, beg = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
      all += gas[i] - cost[i];
      if (tempsum < 0)
      {
        tempsum = gas[i] - cost[i];
        beg = i;
      }
      else
        tempsum += gas[i] - cost[i];
    }
    return all >= 0 ? beg : -1;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 }, target = { 2, 5, 7, 11 };
  int res = slu.canCompleteCircuit(input, target);
  cout << res << endl;
  system("pause");
}
#endif
