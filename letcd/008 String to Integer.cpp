#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int atoi(const char *str) {
    int idx = 0;
    while (str[idx] == ' ') ++idx;
    if (str[idx] == '\0') return 0;
    long long res=0,tag=1;
    if (str[idx] == '-') tag = -1;
    else if (str[idx] == '+') tag = 1;
    else if (isdigit(str[idx])) res = res * 10 + str[idx] - '0';
    else return 0;
    ++idx;
    while (isdigit(str[idx])) {
      res = res*10 + str[idx] - '0';
      if ( res > INT_MAX && tag == 1)
        return INT_MAX;
      else if (res > INT_MAX + (long long)1 && tag == -1)
        return INT_MIN;
      ++idx;
    }
    int resint = res*tag;
    return resint;
  }
};

int main()
{
  Solution slu;
  char cc[] = "    -l000000213j";
  int vecres = slu.atoi(cc);
  cout << vecres<< endl;
  system("pause");
}