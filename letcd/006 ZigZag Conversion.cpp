#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 1) return s;
    int len = s.length(), current_rowid = -1, step = 1;
    vector<string> vecstr(nRows);
    for (int i = 0; i < len; ++i)
    {
      current_rowid += step;
      if (current_rowid == nRows)
      {
        current_rowid -= 2;
        step = -1;
      }
      else if (current_rowid == -1)
      {
        current_rowid += 2;
        step = 1;
      }
      vecstr[current_rowid] += s[i];
    }
    string res;
    for (int i = 0; i < nRows; ++i)
      res += vecstr[i];
    return res;
  }
};

int main()
{
  Solution slu;
  string s = "PAYPALISHIRING";
  string st = slu.convert(s,3);
  cout << st << endl;
  system("pause");
}
#endif
