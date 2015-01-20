#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1,1);
    for (int i = 1; i <= rowIndex; ++i)
    {
      for (int j = i - 1; j > 0; j--)
        res[j] = res[j - 1] + res[j];
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int target = 6;
  vector<int> res = slu.getRow(target);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}