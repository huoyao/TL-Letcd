#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for(size_t i = 1;i < nums.size();++i)
      res[i] = res[i - 1] * nums[i - 1];
    int tmp = 1;
    for(int i = nums.size() - 2;i >= 0;--i)
    {
      tmp *= nums[i + 1];
      res[i] *= tmp;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  vector<int> res = slu.productExceptSelf(input);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}