/*
The API : int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read.For example,
it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n)
that reads n characters from the file.
Note :
The read function may be called multiple times.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int read4(char *buf);

class Solution {
private:
  int bufptr, bufcnt, res;
  char buffer[4];
public:
  Solution(){ res = bufptr = bufcnt = 0; }
  int read(char *buf, int n){
    res = 0;
    while (res < n)
    {
      if (bufptr == 0) bufcnt = read4(buffer);
      if (bufcnt == 0) break;
      while (res < n && bufptr < bufcnt) buf[res++] = buffer[bufptr++];
      if (bufptr == bufcnt) bufptr = 0;
    }
    return res;
};

int main()
{
  Solution slu;
  Solution slu;
  char buf[] = "adsaf";
  int res = slu.read(buf, 3);
  cout << endl;
  system("pause");
  return 0;
}

