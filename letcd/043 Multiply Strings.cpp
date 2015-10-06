#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int len1 = num1.length(), len2 = num2.length(), n1, n2, rem;
    string res = "";
    if (len1 == 0 || len2 == 0 || num1[0] == '0' || num2[0] == '0') return "0";
    vector<int> vecres(len1 + len2, 0);
    for (int i = 0; i < len1; ++i)
    {
      n1 = num1[len1 - i - 1] - '0';
      rem = 0;
      for (int j = 0; j < len2; ++j)
      {
        n2 = num2[len2 - j - 1] - '0';
        int sum = n1*n2 + vecres[i + j] + rem;
        rem = sum / 10;
        vecres[i + j] = sum % 10;
      }
      if (rem>0) vecres[i + len2] += rem;
    }
    int idx = len1 + len2 - 1;
    while (vecres[idx] == 0)--idx;
    while (idx >= 0) res += ('0' + vecres[idx--]);
    return res;
  }
};

int main()
{
  Solution slu;
  string num1 = "3", num2 = "2";
  string res = slu.multiply(num1, num2);
  cout << res << endl;
  system("pause");
}
#endif
