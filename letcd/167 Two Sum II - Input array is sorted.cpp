/*
Given an array of integers that is already sorted in ascending order,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such
that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    long long sum;
    int a = 0, b = numbers.size() - 1;
    while (a<b)
    {
      sum = static_cast<long long>(numbers[a]) + numbers[b];
      if (sum == target){ res = {a+1,b+1};return res;}
      else if (sum>target) --b;
      else ++a;
    }
    return res;
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