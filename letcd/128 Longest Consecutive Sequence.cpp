#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    int res = 0;
    unordered_map<int, int> rangesum;
    for (int i = 0; i < num.size(); ++i)
    {
      int n = num[i];
      if (!rangesum.count(n))
      {
        int left = rangesum.count(n-1) ? rangesum[n-1] : 0;
        int right = rangesum.count(n+1) ? rangesum[n + 1] : 0;
        int sum = left + right + 1;
        rangesum[n] = sum;
        res = max(res, sum);
        rangesum[n - left] = sum;
        rangesum[n + right] = sum;
      }
      else
        continue;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 0,0,-1};
  int target = 9;
  int res = slu.longestConsecutive(input);
  cout << res << endl;
  system("pause");
}