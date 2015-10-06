#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Definition for a point.
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    if (points.size() <= 2) return points.size();
    unordered_map<float, int> mapk;
    int maxnum = 0;
    for (int i = 0; i < points.size(); ++i)
    {
      mapk.clear();
      int dup = 1;
      for (int j = 0; j < points.size(); ++j)
      {
        if (i == j) continue;
        if (points[i].x == points[j].x && points[i].y == points[j].y) { ++dup; continue; }
        float k = points[i].x == points[j].x ? INT_MAX : (points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);
        mapk[k]++;
      }
      for (auto it = mapk.begin(); it != mapk.end(); ++it) maxnum = max(maxnum,it->second+dup);
      maxnum = max(maxnum,dup);  //mark
    }
    return maxnum;
  }
};

int main()
{
  Solution slu;
  vector<Point> points = { Point(1, 1), Point(1, 1), Point(1, 1)};
  int res = slu.maxPoints(points);
  cout << res << endl;
  system("pause");
}
#endif
