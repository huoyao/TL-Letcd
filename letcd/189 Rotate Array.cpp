#include <iostream>
using namespace std;

class Solution
{
public:
  void rotate(int nums[], int n, int k) {
    int cnt = 0,idx=0;
    k %= n;
    while(cnt < n)
    {
      int target = (idx + k)%n,forward=nums[idx];
      do
      {
        int tmp = nums[target];
        nums[target] = forward;
        forward = tmp;
        target = (target + k) % n;
        ++cnt;
      } while(target!=idx);
      nums[idx] = forward;
      ++cnt;
      ++idx;
    }
  }
};

int main()
{
  Solution slu;
  int input[] = { 1,2,3,4,5,6 };
  int n = 6,k=4;
  slu.rotate(input, n, k);
  for(int i = 0;i < n;++i)
    cout << input[i] << "  ";
  cout << endl;
  system("pause");
  return 0;
}