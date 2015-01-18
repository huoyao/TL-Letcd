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
private:
  bool same = true;
public:
  void check(TreeNode *p, TreeNode *q)
  {
    if (!q && !p) return;
    if (q && !p || !q && p|| p->val != q->val) same = false;
    if (!same) return;
    if (p->left || q->left) check(p->left, q->left);
    if (p->right || q->right) check(p->right,q->right);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    check(p,q);
    return same;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(3);
  h->right = new TreeNode(1);
  bool res = slu.isSameTree(h, h);
  cout <<res<< endl;
  system("pause");
}