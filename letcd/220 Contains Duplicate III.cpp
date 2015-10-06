#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
  typedef long long ll;
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() < 2 || k < 1) return false;
    set<ll > nums_remain;
    int idx_low=0;
    for(size_t i = 0;i < nums.size();++i)
    {
      if(i - idx_low>k) nums_remain.erase(nums[idx_low++]);
      auto it = nums_remain.lower_bound((ll)nums[i] - t);
      if(it != nums_remain.end() && *it <= (ll)nums[i] + t) return true;
      nums_remain.insert((ll)nums[i]);
    }
    return false;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { -1,-1 };
  int k = 1, t = 0;
  bool res = slu.containsNearbyAlmostDuplicate(input, k, t);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
