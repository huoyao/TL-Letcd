#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void build(vector<string> &res,const int &n,int siz,string &rec, vector<bool> &isused)
{
  if (siz == n)
    res.push_back(rec);
  else
  {
    for (int i = 0; i < n; ++i)
    {
      if (isused[i]) continue;
      isused[i] = true;
      rec += ('1'+i);
      build(res,n,siz+1,rec,isused);
      isused[i] = false;
      rec.pop_back();
    }
  }
}

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<string> res;
    string record;
    vector<bool> isused(n,false);
    build(res,n,0,record,isused);
    return res[k-1];
  }
};

int main()
{
  Solution slu;
  int input = 3;
  int target = 5;
  string res = slu.getPermutation(input, target);
  cout << res<<endl;
  system("pause");
}