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
  bool isValidBST(TreeNode *root) {
    TreeNode *pre = NULL;
    return isvalid(root,pre);
  }
  bool isvalid(TreeNode *root,TreeNode *&pre)
  {
    if (!root) return true;
    if (!isvalid(root->left, pre)) return false;
    if (pre && pre->val >= root->val) return false;
    pre = root;
    return isvalid(root->right,pre);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2147483647);
  h->left = NULL;
  h->right = new TreeNode(-2147483648);
  bool res = slu.isValidBST(h);
  cout << res<<endl;
  system("pause");
}