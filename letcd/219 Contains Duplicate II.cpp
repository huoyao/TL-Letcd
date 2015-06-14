#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

  class Solution
  {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> idx_map;
      for(size_t i = 0;i < nums.size();++i)
      {
        if(idx_map.count(nums[i]) && i - idx_map[nums[i]] <= k) return true;
        else idx_map[nums[i]] = i;
      }
      return false;
    }
  };

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int target = 2;
  bool res = slu.containsNearbyDuplicate(input, target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}