#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<string> st;
  vector<int> mapidx;
  string mid;
public:
  vector<string> letterCombinations(string digits) {
    mapidx = {0,0,3,6,9,12,15,19,22,26};
    getre(0,digits);
    return st;
  }
  void getre(int idx,string &digits)
  {
    if (idx == digits.length())
    {
      st.push_back(mid);
      return;
    }
    int ind = digits[idx] - '0';
    for (int i = mapidx[ind - 1]; i < mapidx[ind]; ++i)
    {
      mid.push_back('a' + i);
      getre(idx + 1, digits);
      mid.pop_back();  //c++XI
    }
  }
};

int main()
{
  Solution slu;
  string str = "23";
  vector<string> res = slu.letterCombinations(str);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}