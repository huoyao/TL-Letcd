#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.size() < 1) return res;
    res.push_back(to_string(nums[0]));
    int back_num = nums[0];
    for(size_t i = 1;i < nums.size();++i)
    {
      if(nums[i] != nums[i - 1] + 1)
      {
        if(nums[i - 1] !=back_num)res.back() +="->" +to_string(nums[i - 1]);
        res.push_back(to_string(nums[i]));
        back_num = nums[i];
      }
    }
    if(nums.back()!=back_num) res.back() +="->"+ to_string(nums.back());
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 3, 4, 7, 11, 12, 15 };
  int target = 9;
  vector<string> res = slu.summaryRanges(input);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}