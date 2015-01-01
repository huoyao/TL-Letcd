#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    char *lptr = &s[0], *rptr = &s[0];
    vector<bool> vectag(256, false);
    int maxcnt = 0, cnt = 0;
    while (*rptr!='\0')
    {
      if (!vectag[*rptr])
      {
        vectag[*rptr] = true;
        ++cnt; 
        ++rptr;
      }
      else
      {
        if (cnt>maxcnt) maxcnt = cnt;
        while (*lptr != *rptr)
        {
          vectag[*lptr] = false;
          ++lptr;
          --cnt;
        }
        ++lptr;
        //--cnt;   mark 1:str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
        ++rptr;
      }
    }
    if (cnt>maxcnt) maxcnt = cnt;  //mark 2:str="qopubjguxhxdipfzwswybgfylqvjzhar";
    return maxcnt;
  }
};

int main()
{
  Solution slu;
  string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
  int res = slu.lengthOfLongestSubstring(str);
  cout <<res<< endl;
  system("pause");
}