#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void rob_n(const vector<int>& nums, const int&start, const int&end, int &cur_max)
  {
    int pre_no = 0;
    for(size_t i = start;i < end;++i)
    {
      int temp = pre_no;
      pre_no = cur_max;
      cur_max = max(temp + nums[i], cur_max);
    }
  }
  int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    else if(nums.size() == 1) return nums[0];
    int cur_max0 = 0, cur_max1 = 0;
    //not rob nums[0]
    rob_n(nums, 1, nums.size(), cur_max0);
    //not rob nums[n-1]
    rob_n(nums, 0, nums.size() - 1, cur_max1);
    return max(cur_max0, cur_max1);
  }

};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int res = slu.rob(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}