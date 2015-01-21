#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    if (num.size() < 2) return num.size();
    int res = 0;
    unordered_set<int> exit_elem,vist;
    for (int i = 0; i < num.size(); ++i)
      exit_elem.insert(num[i]);
    for (int i = 0; i < num.size(); ++i)
    {
      if (vist.count(num[i])) continue;
      int target = num[i],maxcnt=1;
      while (exit_elem.count(--target)){ ++maxcnt; vist.insert(target); }
      target = num[i];
      while (exit_elem.count(++target)){ ++maxcnt; vist.insert(target); }
      res = max(res,maxcnt);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 100, 4, 200, 1, 3, 2 };
  int target = 9;
  int res = slu.longestConsecutive(input);
  cout << res<<endl;
  system("pause");
}