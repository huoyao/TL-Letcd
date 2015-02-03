#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void getre(int map[],int idx,vector<string> &st,string &mid,string &digits)
{
  if (idx == digits.length())
  {
    st.push_back(mid);
    return;
  }
  int ind = digits[idx] - '0';
  for (int i = map[ind-1]; i < map[ind]; ++i)
  {
    mid.push_back('a'+i);
    getre(map, idx+1, st, mid, digits);
    mid.pop_back();  //c++XI
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    int mapidx[10] = {0,0,3,6,9,12,15,19,22,26};
    vector<string> st;
    string mid="";
    getre(mapidx,0,st,mid,digits);
    return st;
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