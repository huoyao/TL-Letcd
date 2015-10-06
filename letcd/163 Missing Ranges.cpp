#if 0
/*
Given a sorted integer array where the range of 
elements are [lower, upper] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 
and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> res;
public:
  void addrange(const int low,const int up)
  {
    if (low > up) return;
    string str= low == up ? to_string(low) : (to_string(low)+"->"+to_string(up));
    res.push_back(str);
  }
  vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    int beg=0,end=n-1;
    while (A[beg] < lower) ++beg;
    while (A[end]>upper) --end;
    if(beg>0) A[--beg] = lower;
    else addrange(lower,A[0]-1);
    if(end<n-1) A[++end] = upper;
    for (int i = beg; i < end; ++i)
    {
      if (A[i] == A[i + 1]) continue;
      addrange(A[i]+1,A[i+1]-1);
    }
    addrange(A[end]+1,upper);
    return res;
  }
};

int main()
{
  Solution slu;
  int input[] = { 0, 1, 3, 50, 75 };
  int target = 5,low=0,upper=99;
  vector<string> res = slu.findMissingRanges(input, target, low, upper);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
  return 0;
}
#endif
