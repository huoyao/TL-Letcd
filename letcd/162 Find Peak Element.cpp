#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int a = 0, b = num.size() - 1;
    while (a < b)
    {
      int mid = (a + b) >> 1;
      if (num[mid] < num[mid + 1]) a = mid + 1;
      else b = mid;
    }
    return a;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int res = slu.findPeakElement(input);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
