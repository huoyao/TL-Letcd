#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int atoi(const char *str) {
    int idx = 0,tag=1;
    while (str[idx] == ' ') ++idx;
    long long res=0;
    if (str[idx] == '-') { tag = -1; ++idx; }
    else if (str[idx] == '+') { tag = 1; ++idx; };
    while (isdigit(str[idx])) {
      res = res*10 + str[idx] - '0';
      if ( res > INT_MAX && tag == 1)
        return INT_MAX;
      else if (res > INT_MAX + (long long)1 && tag == -1)
        return INT_MIN;
      ++idx;
    }
    return (int)res*tag;
  }
};

int main()
{
  Solution slu;
  char cc[] = "1";
  int vecres = slu.atoi(cc);
  cout << vecres<< endl;
  system("pause");
}