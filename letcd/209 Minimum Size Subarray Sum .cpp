#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    return minSubArrayLenNlogN(s, nums);
  }
  int minSubArrayLenN(const int s, const vector<int>& nums)
  {
    int sum = 0, start = 0,len=INT_MAX;
    for(size_t i = 0;i < nums.size();++i)
    {
      sum += nums[i];
      while(sum >= s)
      {
        len = min(len, (int)i - start+1);
        sum -= nums[start++];
      }
    }
    return len==INT_MAX?0:len;
  }
  int minSubArrayLenNlogN(const int s, const vector<int>& nums)
  {
    int *sums=new int[nums.size()] ;
    if(nums.size() == 0) return 0;
    int len = INT_MAX;
    sums[0] = nums[0];
    for(size_t i = 1;i < nums.size();++i) sums[i] = sums[i - 1] + nums[i];
    for(size_t i = 0;i < nums.size();++i)
    {
      int end = findS(i, nums.size() - 1, sums[i] + s - nums[i], sums);
      if(end == nums.size())break;
      len = min(len, end - (int)i + 1);
    }
    delete sums;
    return len == INT_MAX ? 0 : len;
  }
  int findS(int low,int up,const int&sum,int *sums)
  {
    while(low <= up)
    {
      int mid = (low + up) >> 1;
      if(sums[mid] >= sum) up = mid - 1;
      else low = mid + 1;
    }
    return low;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 1, 4, 4 };
  int target = 4;
  int res = slu.minSubArrayLen(target,input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}