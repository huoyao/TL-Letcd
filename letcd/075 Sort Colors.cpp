#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void sortColors(int A[], int n) {
    if (!A || n < 2) return;
    int redidx = 0, blueidx = n - 1;
    for (int i = 0; i <= blueidx; ++i)
    {
      if (A[i] == 0)
        swap(A[redidx++], A[i]);
      else if (A[i] == 2)
        swap(A[blueidx--],A[i--]);
    }
  }
};

int main()
{
  Solution slu;
  int  input[] = { 1,2,0 };
  int target = 3;
  slu.sortColors(input, target);
  for (auto &t : input)
    cout << t << "  ";
  cout << endl;
  system("pause");
}
#endif
