#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> vecres;
    map<int, int> mapidx;
    for (int i = 0; i < numbers.size(); ++i)
    {
      if (mapidx.find(target - numbers[i]) != mapidx.end())
      {
        vecres.push_back(mapidx[target - numbers[i]]);
        vecres.push_back(i + 1);
        break;
      }
      else
        mapidx[numbers[i]] = i + 1;
    }
    return vecres;
  }
};

int main()
{
  Solution slu;
  vector<int> vecnum = { 0, 0, 11, 15 };
  int target = 0;
  vector<int> vecres = slu.twoSum(vecnum, target);
  cout << *vecres.begin() << "  " << *(vecres.begin() + 1) << endl;
  system("pause");
}