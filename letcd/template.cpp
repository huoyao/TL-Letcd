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
  vector<int> vecnum = {2,7,11,15};
  int target = 9;
  vector<int> vecres = slu.twoSum(vecnum,target);
  cout << *vecres.begin() << "  " << *(vecres.begin() + 1) << endl;
  system("pause");
}