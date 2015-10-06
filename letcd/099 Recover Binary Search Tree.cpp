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
  bool stop = false;
  TreeNode *mis1 = NULL, *mis2 = NULL, *pre = NULL;
  void recoverTree(TreeNode *root) {
    inoder(root);
    if (mis1 && mis2)
      swap(mis1->val, mis2->val);
  }
  void  inoder(TreeNode *rt)
  {
    if (stop || !rt) return;
    if (rt->left)
      inoder(rt->left);
    if (pre != NULL && rt->val < pre->val)
    {
      if (!mis1)
      {
        mis1 = pre;
        mis2 = rt;
      }
      else
      {
        mis2 = rt;
        stop = true;
      }
    }
    pre = rt;
    if (rt->right)
      inoder(rt->right);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(3);
  h->right = new TreeNode(1);
  slu.recoverTree(h);
  system("pause");
}
#endif
