#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {

  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int target = 9;
  vector<int> res = slu.twoSum(input, target);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}