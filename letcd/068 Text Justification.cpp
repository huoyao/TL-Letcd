#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    int wordlen = words.size();
    vector<string> res;
    for (int i = 0,k,len; i < wordlen; i+=k)
    {
      for (k = len = 0; i + k < wordlen && len + words[i + k].size() <= L - k; ++k)
        len += words[i + k].size();
      string tmp = words[i];
      for (int j = 0; j < k - 1; ++j)
      {
        if (i + k >= wordlen) tmp += " ";
        else tmp += string((L-len)/(k-1)+(j<(L-len)%(k-1)),' ');
        tmp += words[i + j + 1];
      }
      tmp += string(L-tmp.size(),' ');
      res.push_back(tmp);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  vector<string> input = { "This", "is", "a", "exmple", "let's", "go!" };
  int target = 9;
  vector<string> res = slu.fullJustify(input, target);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}