#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> uset;
    for(size_t i = 0;i<nums.size();++i)
    {
      if(uset.count(nums[i]) == 0) uset.insert(nums[i]);
      else return true;
    }
    return false;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int target = 9;
  bool res = slu.containsDuplicate(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}