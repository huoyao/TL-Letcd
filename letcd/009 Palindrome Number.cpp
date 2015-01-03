#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;  //mark
    if (x / 10 == 0) return true;
    long long xid = 10;
    while (x / xid)xid *= 10;
    xid /= 10;
    int iidx,jidx;
    while (x)
    {
      iidx = x / xid, jidx = x % 10;
      if (iidx != jidx) return false;
      x -= iidx*xid;
      x /= 10;
      xid /= 100;
    }
    return true;
  }
};

int main()
{
  Solution slu;
  int target = 1000000001;
  bool res = slu.isPalindrome(target);
  cout << res<< endl;
  system("pause");
}