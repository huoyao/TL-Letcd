#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *p) {
    if (!p) return true;
    return check(p->left,p->right);
  }
  bool check(TreeNode *p, TreeNode *q)
  {
    if (!p && !q) return true;
    if (!p && q || p && !q || p->val != q->val) return false;
    return check(p->left, q->right) && check(p->right, q->left);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(3);
  h->right = new TreeNode(1);
  bool res = slu.isSymmetric(h);
  cout << res << endl;
  system("pause");
}
#endif
