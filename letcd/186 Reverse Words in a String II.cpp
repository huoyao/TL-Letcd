#if 0
/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    int len = s.length(), beg = 0, end = len - 1, end2;
    if (len < 2) return;
    while (beg < end) swap(s[beg++], s[end--]);
    beg = end = 0;
    while (end < len)
    {
      while (end < len && s[end] != ' ') ++end;
      end2 = end - 1;
      while (beg < end2) swap(s[beg++], s[end2--]);
      beg = end = end + 1;
    }
  }
};

int main()
{
  Solution slu;
  string input = "this";
  slu.reverseWords(input);
  cout << input << endl;
  system("pause");
  return 0;
}
#endif
