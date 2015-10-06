#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> course(numCourses);
    vector<int> in_degree(numCourses, 0);
    vector<int> res;
    for(size_t i = 0;i < prerequisites.size();++i)
    {
      course[prerequisites[i].second].push_back(prerequisites[i].first);
      ++in_degree[prerequisites[i].first];
    }
    for(size_t i = 0;i < numCourses;++i)
    {
      size_t j = 0;
      for(;j < numCourses && in_degree[j] != 0;++j);
      if(j >= numCourses)
      {
        res.clear();
        return res;
      }
      for(size_t k = 0;k < course[j].size();++k) --in_degree[course[j][k]];
      in_degree[j] = -1;
      res.push_back(j);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<pair<int, int>> input = { { 0, 1 }, { 3, 1 }, { 1, 3 }, {3,2}};
  int target = 4;
  vector<int> res = slu.findOrder(target,input);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
