#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void cal(vector<int> &vecres, const int &mul, const int &idx, const vector<int> &numb, const int &len)
{
  int id = idx, rem = 0;
  for (int i = 0; i < len; ++i)
  {
    int sum = rem + mul*numb[i];
    vecres[id] += sum;
    rem = vecres[id] / 10;
    vecres[id] %= 10;
    ++id;
  }
  if (rem>0)
    vecres[id] += rem;
}

class Solution {
public:
  string multiply(string num1, string num2) {
    int len1 = num1.length(), len2 = num2.length();
    if (len1 == 0 || len2 == 0 || num1[0] == '0' || num2[0] == '0') return "0";
    vector<int> vecres(len1 + len2, 0), numa(len1), numb(len2);
    for (int i = 0; i < len1; ++i)
      numa[i] = num1[len1 - i - 1] - '0';
    for (int i = 0; i < len2; ++i)
      numb[i] = num2[len2 - i - 1] - '0';
    for (int i = 0; i < len1; ++i)
      cal(vecres, numa[i], i, numb, len2);
    string res;
    int idx = len1+len2-1;
    while (vecres[idx] == 0)--idx;
    while (idx >= 0) res += ('0'+vecres[idx--]);
    return res;
  }
};

int main()
{
  Solution slu;
  string num1 = "3", num2 = "234";
  string res = slu.multiply(num1, num2);
  cout << res << endl;
  system("pause");
}