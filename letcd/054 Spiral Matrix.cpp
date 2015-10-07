#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) { 
    int beg_x = 0, beg_y = 0, end_y = matrix.size(), end_x = end_y ? matrix[0].size() : 0;
    vector<int> res(end_x--*end_y--);
    int i=0,id=0;
    while(beg_x<end_x && beg_y<end_y) {
      for(i = beg_x;i < end_x;++i) res[id++] = matrix[beg_y][i];
      for(i = beg_y;i < end_y;++i) res[id++] = matrix[i][end_x];
      for(i = end_x;i > beg_x;--i) res[id++] = matrix[end_y][i];
      for(i = end_y;i > beg_y;--i) res[id++] = matrix[i][beg_x];
      ++beg_x, ++beg_y,  --end_x,--end_y;
    }
    if(beg_x == end_x) for(i = beg_y;i <= end_y;++i) res[id++] = matrix[i][beg_x];
    else if(beg_y == end_y) for(i = beg_x;i <= end_x;++i) res[id++] = matrix[beg_y][i];
    return res;
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
  vector<int> res = slu.spiralOrder(input);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}
#endif
