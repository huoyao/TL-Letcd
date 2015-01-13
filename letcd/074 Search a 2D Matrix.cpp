#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int row = matrix.size(), col = matrix.size() ? matrix[0].size() : 0;
    if (row == 0 || col == 0) return false;
    int a = 0, b = row-1,id;
    while (a <= b)
    {
      int mid = (a + b) >> 1;
      if (target == matrix[mid][0]) return true;
      if (target > matrix[mid][0]) a = mid + 1;
      else b = mid - 1;
    }
    id = max(0,min(a, b)); //mark
    a = 1;
    b = col-1;
    while (a <= b)
    {
      int mid = (a + b) >> 1;
      if (target == matrix[id][mid]) return true;
      if (target > matrix[id][mid]) a = mid + 1;
      else b = mid - 1;
    }
    return false;
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 1, 1}};
  int target = 0;
  bool res = slu.searchMatrix(input, target);
  cout << res<<endl;
  system("pause");
}