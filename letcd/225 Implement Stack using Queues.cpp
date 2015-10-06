#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Stack
{
public:
  // Push element x onto stack.
  void push(int x) {
    const size_t &len = queue_st.size();
    queue_st.push(x);
    for(size_t i = 0;i < len;++i)
    {
      queue_st.push(queue_st.front());
      queue_st.pop();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    queue_st.pop();
  }

  // Get the top element.
  int top() {
    return queue_st.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return queue_st.empty();
  }
private:
  queue<int> queue_st;
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  int target = 9;
  vector<int> res = slu.twoSum(input, target);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
