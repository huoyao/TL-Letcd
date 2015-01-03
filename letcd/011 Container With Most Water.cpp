#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1, con = 0;
    while (l < r)
    {
      con = max(con, min(height[l], height[r])*(r - l));
      if (height[l] < height[r])
      {
        int k = l;
        while (k < r && height[k] <= height[l]) ++k;
        l = k;
      }
      else
      {
        int k = r;
        while (k>l && height[k] <= height[r]) --k;
        r = k;
      }
    }
    return con;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 2, 7, 11, 15 };
  int target = slu.maxArea(vecnum);
  cout << target << endl;
  system("pause");
}