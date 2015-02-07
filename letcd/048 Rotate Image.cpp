#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix[0].size(),cnt = n / 2,round=n-1;
    if (n <= 1) return;
    for (int j = 0; j < cnt; ++j)
    {
      int tag1 = j + n -1, tag2 = tag1, tag3 = j;
      for (int i = j; i < round; ++i)
      {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[tag1][j];
        matrix[tag1][j] = matrix[tag2][tag1];
        matrix[tag2][tag1] = matrix[tag3][tag2];
        matrix[tag3][tag2] = tmp;
        --tag1;
        ++tag3;
      }
      n-=2;
      round -= 1;
    }
  }
};

int main()
{
  Solution slu;
  //vector<vector<int> > input = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, {13,14,15,16} };
  vector<vector<int> > input = { { 1, 2 }, {3,4} };
  slu.rotate(input);
  for (auto &t : input)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}