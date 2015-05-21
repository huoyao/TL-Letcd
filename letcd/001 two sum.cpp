/**********************************************************
                              001 Two Sum
  Given an array of integers, find two numbers such that
they add up to a specific target number.
  The function twoSum should return indices of the two
numbers such that they add up to the target,
where index1 must be less than index2. Please note that
your returned answers (both index1 and index2)
are not zero-based.
  You may assume that each input would have exactly one
solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
**********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> vecres;
    unordered_map<int, int> mapidx;
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
  cout << vecres[0]<< " " << vecres[1] << endl;
  system("pause");
}