#if 0
/*
Design and implement a TwoSum class. It should support the following operations:add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class TwoSum {
private:
  unordered_map<int, int> mapnum;
public:
  void add(int number) {
    ++mapnum[number];
  }

  bool find(int value) {
    for (auto it = mapnum.begin(); it != mapnum.end(); ++it)
    {
      int num = value - it->first;
      if (num == it->first && it->second > 1 || num != it->first && mapnum.count(num))
        return true;
    }
    return false;
  }
};

int main()
{
  TwoSum slu;
  slu.add(1);
  slu.add(3);
  cout << slu.find(1) << " " << slu.find(4);
  cout << endl;
  system("pause");
  return 0;
}
#endif
