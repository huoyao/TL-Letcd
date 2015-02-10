#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') continue;
      int pos = i;
      while (i < s.length() && s[i] != ' ') i++;
      if (result.length() > 0) result = ' ' + result;
      result = s.substr(pos, i - pos) + result;
      i--;
    }
    s = result;
  }
};

int main()
{
  Solution slu;
  string str = "k";
  int target = 9;
  slu.reverseWords(str);
  cout << str << endl;
  system("pause");
}