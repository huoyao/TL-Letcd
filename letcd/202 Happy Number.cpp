#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool isHappy(int n) {
    unordered_set<int> all_num;
    int sum,tmp;
    while(n != 1)
    {
      if(all_num.count(n)) return false;
      all_num.insert(n);
      sum = 0;
      while(n)
      {
        tmp = n % 10;
        sum += tmp*tmp;
        n /= 10;
      }
      n = sum;
    }
    return true;
  }
};

int main()
{
  Solution slu;
  int target = 19;
  bool res = slu.isHappy(target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}