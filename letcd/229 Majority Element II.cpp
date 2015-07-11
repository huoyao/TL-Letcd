#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int x = 0, y = 1, cnt_x = 0, cnt_y = 0;
    for(size_t i = 0;i < nums.size();++i) 
    {
      if(nums[i] == x) ++cnt_x;
      else if(nums[i] == y) ++cnt_y;
      else if(cnt_x == 0) cnt_x=1,x=nums[i];
      else if(cnt_y == 0) cnt_y = 1, y = nums[i];
      else --cnt_x, --cnt_y;
    }
    cnt_x = cnt_y = 0;
    for(size_t i = 0;i < nums.size();++i)
    {
      if(nums[i] == x) ++cnt_x;
      else if(nums[i] == y) ++cnt_y;
    }
    const int &cnt = nums.size() / 3;
    if(cnt_x>cnt) res.push_back(x);
    if(cnt_y > cnt) res.push_back(y);
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2,2, 7, 11, 15,2,3,3,3 };
  int target = 9;
  vector<int> res = slu.majorityElement(input);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}