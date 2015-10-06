#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Solution
{
public:
  int countPrimes(int n) {
    int num = 0;
    int *prim = (int *)malloc(n*sizeof(int));
    memset(prim, 0, sizeof(int)*n);
    for(size_t i = 2;i < n;++i)
    {
      if(prim[i] == 0)
      {
        ++num;
        for(size_t j = i * 2;j < n;j += i) prim[j] = 1;
      }
    }
    free(prim);
    return num;
  }
};

int main()
{
  Solution slu;
  int target = 9;
  int res = slu.countPrimes(target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
