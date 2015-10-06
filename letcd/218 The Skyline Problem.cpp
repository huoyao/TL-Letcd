#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
using namespace std;

class Solution
{
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    multimap<int, int> map_point;
    multiset<int,greater<int>> set_height;
    vector<pair<int, int>> res;
    for(size_t i = 0;i < buildings.size();++i)
    {
      vector<int> &vec = buildings[i];
      map_point.insert(pair<int,int>(vec[0],vec[2]));
      map_point.insert(pair<int, int>(vec[1], -vec[2]));
    }
    set_height.insert(0);
    while(!map_point.empty())
    {
      int last_height = *set_height.begin();
      int cur_x = map_point.begin()->first;
      while(!map_point.empty() && cur_x == map_point.begin()->first)
      {
        int x_height = map_point.begin()->second;
        if(x_height > 0) set_height.insert(x_height);
        else set_height.erase(set_height.find(-x_height));
        map_point.erase(map_point.begin());
      }
      if(last_height != *set_height.begin()) res.push_back(pair<int, int>(cur_x, *set_height.begin()));
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<vector<int>> input = { { 0, 3, 3 }, { 1, 5, 3 }, { 2, 4, 3 }, { 3, 7, 3 } };
  vector<pair<int, int>> res = slu.getSkyline(input);
  for(auto &t : res)
    cout << t.first << " " << t.second << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
