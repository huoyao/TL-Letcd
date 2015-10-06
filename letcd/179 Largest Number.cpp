#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



class Solution {
public:
  string largestNumber(vector<int> &num) {
    string res = "";
    vector<string> vecstr(num.size());
    for (int i = 0; i < num.size(); ++i)
      vecstr[i] = to_string(num[i]);
    sort(vecstr.begin(), vecstr.end(), cmp);
    for (int i = 0; i < vecstr.size(); ++i)
      res += vecstr[i];
    int idx = 0;
    while (res[idx] == '0') ++idx;
    if (idx==res.length()) return "0";  //mark
    return res;
  }
  static bool cmp(const string &a, const string &b)
  {
    string c1 = a + b, c2 = b + a;
    return c1 > c2;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 0, 00 };
  string res = slu.largestNumber(input);
  cout << res << endl;
  system("pause");
  return 0;
}
#endif
