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
  void flatten(TreeNode *root) {
    TreeNode *pre = NULL;
    flat(root, pre);
  }
  void flat(TreeNode *rt, TreeNode *&pre)
  {
    if (!rt) return;
    if (pre) pre->right = rt;
    pre = rt;
    TreeNode *rec = rt->right;
    flat(rt->left, pre);
    rt->left = NULL;
    flat(rec, pre);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(3);
  slu.flatten(h);
  cout << endl;
  system("pause");
}