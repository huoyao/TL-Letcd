#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  string shortestPalindrome(string s) {
    string s_bak = s;
    reverse(s_bak.begin(), s_bak.end());
    string rev_s = s_bak;
    s_bak = s+'#' + s_bak;
    vector<int> prefix_match(s_bak.size(), 0);
    for(size_t i = 1;i < s_bak.size();++i)
    {
      int j = prefix_match[i-1];
      while(j>0 && s_bak[i] != s_bak[j]) j = prefix_match[j - 1];
      prefix_match[i] += (j += s_bak[i] == s_bak[j]);
    }
    return rev_s.substr(0, s.size() - prefix_match[prefix_match.size() - 1]) + s;
  }
};

int main()
{
  Solution slu;
  string input = "abbacd";
  string res = slu.shortestPalindrome(input);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}