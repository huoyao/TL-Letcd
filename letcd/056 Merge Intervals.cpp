#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> res;
    if (intervals.size() <= 0) return res;
    sort(intervals.begin(), intervals.end(), cmp);
    Interval tmp(intervals[0].start,intervals[0].end);
    for (int i=1; i < intervals.size(); ++i)
    {
      if (intervals[i].start <= tmp.end)
        tmp.end = max(tmp.end,intervals[i].end);
      else
      {
        res.push_back(tmp);
        tmp = intervals[i];
      }
    }
    res.push_back(tmp);
    return res;
  }
  static bool cmp(const Interval &t1, const Interval &t2)
  {
    if (t1.start == t2.start)
      return t1.end < t2.end;
    return t1.start < t2.start;
  }
};

int main()
{
  Solution slu;
  vector<Interval> input = { Interval(1,2),Interval(2,3),Interval(4,5)};
  vector<Interval> res = slu.merge(input);
  for (auto &t : res)
    cout << t.start << "  "<<t.end<<endl;
  system("pause");
}
#endif
