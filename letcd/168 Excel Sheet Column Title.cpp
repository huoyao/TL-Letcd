#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string res;
    --n;
    int idx = n % 26;
    while (idx>=0)
    {
      res = static_cast<char>('A'+idx)+res;
      n /= 26;
      --n;
      idx = n % 26;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int target = 701;
  string res = slu.convertToTitle(target);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
