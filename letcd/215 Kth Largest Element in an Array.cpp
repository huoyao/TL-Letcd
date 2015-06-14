#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int partition(vector<int>& nums,const int &k, int start,int end)
  {
    int target = start;
    swap(nums[k], nums[start ++]);
    while(start <= end)
    {
      while(nums[start]>nums[target]) ++start;
      while(nums[end] < nums[target]) --end;
      if(start >= end) break;
      swap(nums[start++], nums[end--]);
    }
    swap(nums[end], nums[target]);
    return end;
  }
  int findKthLargest(vector<int>& nums, int k) {
    int k_bak = k - 1, start = 0, end = nums.size() - 1;
    int res = -1;
    while(res != k_bak)
    {
      res = partition(nums, k_bak, start, end);
      if(res > k_bak)
        end = res - 1;
      else if(res < k_bak)
        start = res + 1;
    }
    return nums[k - 1];
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 3, 2, 1, 5, 6, 4 };
  int target = 2;
  int res = slu.findKthLargest(input, target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}