#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
  stack<TreeNode *> stk;
  TreeNode *cur;
public:
  BSTIterator(TreeNode *root) {
    cur = root;
  }
  bool hasNext() {
    return cur || !stk.empty();
  }
  int next() {
    while (!stk.empty() || cur)
    {
      if (cur)
      {
        stk.push(cur);
        cur = cur->left;
      }
      else
      {
        cur = stk.top()->right;
        break;
      }
    }
    TreeNode *tr = stk.top();
    stk.pop();
    return tr->val;
  }
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  BSTIterator slu = BSTIterator(root);
  while (slu.hasNext()) cout << slu.next() << "  ";
  cout << endl;
  system("pause");
  return 0;
}