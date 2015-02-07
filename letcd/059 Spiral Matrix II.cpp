#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    int id = n / 2, round1 = n - 1, i = 0,cnt=1;
    vector<vector<int> > matrix(n, vector<int>(n));
    for (; i < id; ++i)
    {
      int idx1 = i, idx2 = i;
      while (idx1 < round1) matrix[i][idx1++]=cnt++;
      while (idx2 < round1) matrix[idx2++][idx1]=cnt++;
      while (idx1 > i) matrix[idx2][idx1--]=cnt++;
      while (idx2 > i) matrix[idx2--][idx1]=cnt++;
      --round1;
    }
    if (n % 2) matrix[i][i] = cnt;
    return matrix;
  }
};

int main()
{
  Solution slu;
  int target = 5;
  vector<vector<int> > res = slu.generateMatrix(target);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}