#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack {
private:
  stack<int> stk, minstk;
public:
  void push(int x) {
    stk.push(x);
    if (minstk.empty()) minstk.push(x);
    else { int t = minstk.top(); minstk.push(min(x,t)); }
  }
  void pop() {
    stk.pop();
    minstk.pop();
  }
  int top() {
    return stk.top();
  }
  int getMin() {
    return minstk.top();
  }
};

int main()
{
  MinStack slu;
  slu.push(3);
  cout << endl;
  system("pause");
}