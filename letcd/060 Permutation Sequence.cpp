#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    int nmax = 1;
    vector<int> num(n);
    string res="";
    for (int i = 1; i <= n; ++i)
    {
      num[i - 1] = i;
      nmax *= i;
    }
    --k;
    for (int i = 0; i < n; ++i)
    {
      nmax /= n - i;
      int id = k / nmax;
      res += ('0' + num[id]);
      for (int j = id; j < n - i - 1; ++j)
        num[j] = num[j+1];
      k %= nmax;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int input = 9;
  int target = 54494;
  string res = slu.getPermutation(input, target);
  cout << res<<endl;
  system("pause");
}