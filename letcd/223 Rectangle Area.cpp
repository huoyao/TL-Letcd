#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int rec_area = (C - A)*(D - B) + (G - E)*(H - F);
    int x0 = max(A, E), y0 = max(B, F), x1 = min(C, G), y1 = min(D, H);
    if(x1 > x0 && y1 > y0)
      rec_area -= (x1 - x0)*(y1 - y0);
    return rec_area;
  }
};

int main()
{
  Solution slu;
  int res = slu.computeArea(-2, -2, 2, 2, 3, 3, 4, 4);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
