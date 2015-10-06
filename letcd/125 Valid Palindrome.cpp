#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int a = 0, b = s.length()-1;
    while (a < b)
    {
      while (!isalnum(s[a]) && a<b) ++a;
      while (!isalnum(s[b]) && a<b) --b;
      if (a >= b) return true;
      if (tolower(s[a]) != tolower(s[b])) return false;
      ++a;
      --b;
    }
    return true;
  }
};

int main()
{
  Solution slu;
  string input="Aa";
  int target = 9;
  bool res = slu.isPalindrome(input);
  cout << res << endl;
  system("pause");
}
#endif
