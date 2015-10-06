#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &num) {
    int res = num[0], cnt = 1;
    for (int i = 1; i < num.size(); ++i)
    {
      if (num[i] == res) ++cnt;
      else if (cnt) --cnt;
      else { res = num[i]; cnt = 1; }
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 4,4,42, 3, 4 };
  int res = slu.majorityElement(input);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
