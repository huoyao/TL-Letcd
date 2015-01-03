#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    vector<vector<string> > vecstr(4);
    vecstr[0] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    vecstr[1] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vecstr[2] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vecstr[3] = {"","M","MM","MMM"};
    int idx,cnt=0;
    string res="";
    while (num)
    {
      idx = num % 10;
      res = vecstr[cnt++][idx] + res;
      num /= 10;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  int target = 3999;
  string res = slu.intToRoman(target);
  cout << res<< endl;
  system("pause");
}