#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()) return false;
    int low = 0, up = matrix.size()-1;
    if(locateSearchRange(matrix, 0, target, low, up))return true;
    low = 0;
    int up_bak = up;
    if(locateSearchRange(matrix, matrix[0].size()-1, target, low, up))return true;
    low = up + 1;
    for(int i = low;i <= up_bak;++i)
    {
      if(findBinary(matrix,i, target))return true;
    }
    return false;
  }
  bool locateSearchRange(const vector<vector<int>>& matrix, const int &id, const int &target,
                         int &low, int &up)
  {
    while(low <= up)
    {
      int mid = (low + up) >> 1;
      if(matrix[mid][id] < target) low = mid + 1;
      else if(matrix[mid][id] > target) up = mid - 1;
      else { return true; }
    }
    return false;
  }
  bool findBinary(const vector<vector<int>>& matrix, const int &id, const int &target)
  {
    int low = 0, up = matrix[id].size() - 1;
    while(low <= up)
    {
      int mid = (low + up) >> 1;
      if(matrix[id][mid] < target) low = mid + 1;
      else if(matrix[id][mid] > target) up = mid - 1;
      else { return true; }
    }
    return false;
  }
};

int main()
{
  Solution slu;
  vector<vector<int>> input = {
    { -5 }
  };
  int target = -10;
  bool res = slu.searchMatrix(input, target);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}