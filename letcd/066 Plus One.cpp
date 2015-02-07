#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int len = digits.size() - 1;
    for (int i = len; i >=0; --i)
    {
      if (digits[i] == 9)
        digits[i] = 0;
      else
      {
        ++digits[i];
        return;
      }
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 9, 9, 9, 7 };
  vector<int> res = slu.plusOne(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}