#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int idx = 0, cnt = 0;
    while (s[idx] == ' ') ++idx;
    while (s[idx] != '\0')
    {
      cnt = 0;
      while (isalpha(s[idx])) { ++cnt; ++idx; }
      while (s[idx] == ' ') ++idx; 
    }
    return cnt;
  }
};

int main()
{
  Solution slu;
  char input[] = "go to hell god bless you";
  int target = 9;
  int res = slu.lengthOfLastWord(input);
  cout <<res<< endl;
  system("pause");
}
#endif
