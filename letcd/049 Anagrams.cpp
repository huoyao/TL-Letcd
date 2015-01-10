#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    map<string, string> mapt;
    string target;
    vector<string> vecres;
    for (int i = 0; i < strs.size(); ++i)
    {
      string tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      if (mapt.find(tmp) == mapt.end())
        mapt[tmp] = strs[i];
      else
      {
        if (mapt[tmp] != "A")
          vecres.push_back(mapt[tmp]);
        mapt[tmp] = "A";
        vecres.push_back(strs[i]);
      }
    }
    return vecres;
  }
};

int main()
{
  Solution slu;
  vector<string> input = { "ate", "eat", "tea","and","dan" };
  vector<string> res = slu.anagrams(input);
  for (auto &t : res)
    cout << t << endl;
  system("pause");
}