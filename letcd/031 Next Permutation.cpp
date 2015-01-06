#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    if (num.size() <= 1) return;
    int i = num.size() - 2;
    while (i >= 0 && num[i] >= num[i + 1]) --i;
    if (i == -1)
    {
      sort(num.begin(),num.end());
      return;
    }
    int j = i+2;
    while (j < num.size() && num[j] > num[i]) ++j;
    --j;
    num[i] ^= num[j];
    num[j] ^= num[i];
    num[i] ^= num[j];
    sort(num.begin()+i+1,num.end());
    return;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 1,3,2};
  slu.nextPermutation(vecnum);
  for (auto &t:vecnum)
  cout << t << endl;
  system("pause");
}