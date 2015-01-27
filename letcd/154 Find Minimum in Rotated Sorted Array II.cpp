#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &num) {
    int a = 0, b = num.size() - 1, len = num.size() - 1;
    int mine = INT_MAX;
    while (a <= b)
    {
      int mid = (a + b) >> 1;
      mine = min(mine, num[mid]);
      if (a == b) break;
      if (num[mid] < num[b] || mid == b) b = mid - 1;
      if (num[mid] > num[a] || mid == a) { mine = min(mine, num[a]); a = mid + 1; }
      while (num[mid] == num[b]) --b;
      while (num[mid] == num[a]) ++a;
    }
    return mine;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 3, 1, 1 };
  int res = slu.findMin(input);
  cout << res << endl;
  system("pause");
}