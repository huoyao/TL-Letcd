#if 0
/*
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that readsn characters from the file.
Note:
The read function will only be called once for each test case.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int read4(char *buf);

class Solution {
public:
  int read(char *buf, int n) {
    char buffer[4];
    int idx = 0;
    while (true) {
      int cur = read4(buffer);
      int curlen = min(cur,n-idx);
      for (int i = 0; i < curlen; ++i)
        buf[idx + i] = buffer[i];
      idx += curlen;
      if (curlen < 4 || idx == n) return idx;
    }
  }
};

int main()
{
  Solution slu;
  char buf[] = "adsaf";
  int res = slu.read(buf, 3);
  cout << endl;
  system("pause");
  return 0;
}
#endif
