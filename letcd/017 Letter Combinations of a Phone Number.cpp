#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void getre(string map[],int idx,vector<string> &st,string &mid,string &digits)
{
  if (idx == digits.length())
  {
    st.push_back(mid);
    return;
  }
  int ind = digits[idx] - '0';
  for (int i = 0; i < map[ind].length(); ++i)
  {
    mid+= map[ind][i];
    getre(map, idx+1, st, mid, digits);
    mid.pop_back();  //c++XI
  }
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string map[10];
    map[0] = "";
    map[1] = "";
    for (int i = 2; i <8; ++i)
    {
      char c = 'a' + (i-2)*3 ;
      map[i] = c;
      map[i] += (c+1);
      map[i] += (c+2);
    }
    map[7] += "s";
    map[8] = "tuv";
    map[9] = "wxyz";
    vector<string> st;
    string mid="";
    getre(map,0,st,mid,digits);
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