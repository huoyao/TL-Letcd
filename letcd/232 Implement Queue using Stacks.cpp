#if 0
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Queue
{
public:
  // Push element x to the back of queue.
  void push(int x) {
    st1.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if(!empty())
    {
      peek();
      st2.pop();
    }
  }

  // Get the front element.
  int peek(void) {
    if(!st2.empty()) return st2.top();
    else
    {
      while(!st1.empty())
      {
        const int &tmp = st1.top();
        st1.pop();
        st2.push(tmp);
      }
      if(!st2.empty()) return st2.top();
    }
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return st1.empty() && st2.empty();
  }
private:
  stack<int> st1, st2;
};

int main()
{
  Queue slu;
  slu.push(1);
  cout << slu.peek();
  cout << endl;
  system("pause");
  return 0;
}
#endif
