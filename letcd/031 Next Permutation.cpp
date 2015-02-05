#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    if (num.size() <= 1) return;
    int i = num.size() - 1, j;
    for (j = i - 1; j >= 0; --j) if (num[j] < num[j + 1]) break;
    if (j >= 0)
    {
      while (num[i] <= num[j]) --i;
      swap(num[i],num[j]);
    }
    reverse(num.begin() + j + 1, num.end());
    return;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 1, 3};
  slu.nextPermutation(vecnum);
  for (auto &t : vecnum)
    cout << t << endl;
  system("pause");
}