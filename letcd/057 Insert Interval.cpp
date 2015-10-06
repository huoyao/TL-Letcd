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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    if (intervals.size() <= 0)  //mark
    {
      res.push_back(newInterval);
      return res;
    }
    int lval = newInterval.start, rval = newInterval.end, len = intervals.size(), idx = 0;
    while (idx < len && intervals[idx].end < lval) res.push_back(intervals[idx++]);
    if (idx == len)
    {
      res.push_back(newInterval);
      return res;
    }
    Interval tmp = intervals[idx];
    while (idx < len && intervals[idx].start <= rval) ++idx;
    tmp.end = max(intervals[idx - 1].end, rval);
    tmp.start = min(tmp.start, lval);  //mark
    res.push_back(tmp);
    while (idx < len) res.push_back(intervals[idx++]);
    return res;
  }
};

int main()
{
  Solution slu;
  vector<Interval> input = { Interval(1, 2), Interval(4, 7), Interval(10, 15) };
  Interval target(5,12);
  vector<Interval> res = slu.insert(input,target);
  for (auto &t : res)
    cout << t.start << "  " << t.end << endl;
  system("pause");
}
#endif
