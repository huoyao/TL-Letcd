#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> qu;
    vector<int> res;
    if(nums.empty()) return res;
    res.reserve(nums.size() - k + 1);
    size_t i = 0;
    for(;i < k;++i)
      insert(i, qu,nums);
    res.push_back(nums[qu.front()]);
    for(;i < nums.size();++i)
    {
      if(i - qu.front() == k) qu.pop_front();
      insert(i, qu,nums);
      res.push_back(nums[qu.front()]);
    }
    return res;
  }
  void insert(const int &i, deque<int> &qu,const vector<int> &nums)
  {
    while(!qu.empty() && nums[i] >= nums[qu.back()]) qu.pop_back();
    qu.push_back(i);
  }
};

int main()
{
  Solution slu;
  vector<int> input = {1, 3, 1, 2, 0, 5 };
  int target = 3;
  vector<int> res = slu.maxSlidingWindow(input, target);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}