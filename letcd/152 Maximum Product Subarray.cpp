#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    long long maxnum = 0, curmax = 1, curmin = 1,next_min,next_max;
    for (int i = 0; i < len; ++i)
    {
      next_min = curmin*nums[i];
      next_max = curmax*nums[i];
      curmin = min(static_cast<long long>(nums[i]),min(next_min,next_max));
      curmax = max(static_cast<long long>(nums[i]),max(next_min, next_max));
      maxnum = max(maxnum,curmax);
    }
    return maxnum;
  }
};

int main()
{
  Solution slu;
  int input[] = { 2, -7, 11, 15 };
  int target = 4;
  int res = slu.maxProduct(input, target);
  cout << res << endl;
  system("pause");
}
#endif
