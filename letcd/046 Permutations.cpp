#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(vector<int> &num,int beg,vector<vector<int> > &res)
{
  if (beg >= num.size())
  {
    res.push_back(num);
    return;
  }
  for (int i = beg; i < num.size(); ++i)
  {
    swap(num[beg],num[i]);
    find(num,beg+1,res);
    swap(num[beg],num[i]);
  }
}

class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > res;
    find(num,0,res);
    return res;
  } 
};

int main()
{
  Solution slu;
  vector<int> input = { 1,1 };
  vector<vector<int> > res = slu.permute(input);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}