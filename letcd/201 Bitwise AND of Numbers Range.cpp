#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int rangeBitwiseAnd(int m, int n) {
    if(m == 0) return 0;
    int m_factor = 1;
    while(m != n)
    {
      m >>= 1;
      n >>= 1;
      m_factor <<= 1;
    }
    return m*m_factor;
  }
};

int main()
{
  Solution slu;
  int input = 5, target = 7;
  int res = slu.rangeBitwiseAnd(input, target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}