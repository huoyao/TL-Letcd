#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int rob(vector<int> &num) {
    int preNo = 0, preYes = 0;//the forward element add or not
    int tmp;
    for(size_t i = 0;i < num.size();++i)
    {
      tmp = preNo;
      preNo = max(preNo, preYes);
      preYes = num[i] + tmp;
    }
    return max(preNo, preYes);
  }
};

int main()
{
  Solution slu;
  vector<int> num = { 1, 2, 3, 4 };
  int res = slu.rob(num);
  cout << res << endl;
  system("pause");
  return 0;
}