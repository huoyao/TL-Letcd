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
  bool has = false;
public:
  void doHas(TreeNode *root, int sum,int rec)
  {
    if (!root) return;
    if (!root->left && !root->right)
    {
      if (sum == rec) has = true;
      return;
    }
    if (!has && root->left) doHas(root->left, sum, rec + root->left->val);
    if (!has && root->right) doHas(root->right, sum, rec + root->right->val);
  }

  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    doHas(root,sum,root->val);
    return has;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  //h->left = new TreeNode(1);
  h->right = new TreeNode(1);
  bool res = slu.hasPathSum(h,0);
  cout << res<<endl;
  system("pause");
}