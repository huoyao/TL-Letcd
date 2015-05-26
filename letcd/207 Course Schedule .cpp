#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution
{
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> course(numCourses);
    vector<int> in_degree(numCourses,0);
    for(size_t i = 0;i < prerequisites.size();++i)
    {
      course[prerequisites[i].second].push_back(prerequisites[i].first);
      ++in_degree[prerequisites[i].first];
    }
    for(size_t i = 0;i < numCourses;++i)
    {
      size_t j=0;
      for(;j < numCourses && in_degree[j] != 0;++j);
      if(j >= numCourses) return false;
      for(size_t k = 0;k < course[j].size();++k) --in_degree[course[j][k]];
      in_degree[j] = -1;
    }
    return true;
  }
  bool DFS(vector<bool> &done, vector<bool> &vist,const int&id,const vector<vector<int>> &numCourse)
  {
    done[id] = true;
    vist[id] = true;
    for(size_t i = 0;i < numCourse[id].size();++i)
    {
      if(vist[numCourse[id][i]] || DFS(done, vist, numCourse[id][i], numCourse))
        return true;
    }
    vist[id] = false;
    return false;
  }
  bool canFinish_(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> course(numCourses);
    for(size_t i = 0;i < prerequisites.size();++i)
      course[prerequisites[i].second].push_back(prerequisites[i].first);
    vector<bool> done(numCourses, false),vist(numCourses, false);
    for(size_t i = 0;i < numCourses;++i)
    {
      if(!done[i] && DFS(done, vist, i, course))
        return false;
    }
    return true;
  }
};

int main()
{
  Solution slu;
  vector<pair<int, int>> input = { {0, 1}, {3, 1}, {1, 3}, {3, 2} };
  int target = 4;
  bool res = slu.canFinish(target, input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}