#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    int num = 1 << n,i=0;
    vector<int> res;
    while (i < num)res.push_back((i>>1)^(i++));
    return res;
  }
};

int main()
{
  Solution slu;
  int input = 2;
  vector<int> res = slu.grayCode(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}
#endif
