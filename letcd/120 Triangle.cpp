#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.size() == 0) return 0;
    vector<int> minres(triangle[triangle.size()-1].size(),0);
    for (int i = 0; i < triangle.size(); ++i)
    {
      int len = triangle[i].size();
      if (i != 0) minres[len - 1] = minres[len - 2]+ triangle[i][len-1];
      for (int j=len-2; j > 0; --j)
      {
        minres[j] = min(minres[j-1]+triangle[i][j],minres[j]+triangle[i][j]);
      }
      minres[0] += triangle[i][0];
    }
    int minelem = INT_MAX;
    for (int i = 0; i < minres.size(); ++i) minelem = min(minelem,minres[i]);
    return minelem;
  }
};

int main()
{
  Solution slu;
  vector<vector<int> > input = { { 2 }, { 3, 4 }, { 6, 5, 7 }, {4,1,8,3} };
  int res = slu.minimumTotal(input);
  cout << res<<endl;
  system("pause");
}