#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;  //mark
    long long reverseX = 0,bakX=x;
    while (bakX)
    {
      reverseX = reverseX * 10 + bakX % 10;
      bakX /= 10;
    }
    return reverseX==x;
  }
};

int main()
{
  Solution slu;
  int target = 1;
  bool res = slu.isPalindrome(target);
  cout << res<< endl;
  system("pause");
}
#endif
