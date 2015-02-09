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
  int sumNumbers(TreeNode *root) {
    if (!root) return 0;
    int rec = root->val,res=0;
    dfs(root,rec,res);
    return res;
  }
  void dfs(TreeNode *root, int rec, int &res)
  {
    if (!root->left && !root->right)
    {
      res += rec;
      return;
    }
    if (root->left)
      dfs(root->left, rec * 10 + root->left->val, res);
    if (root->right)
      dfs(root->right, rec * 10 + root->right->val, res);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(1);
  h->left = new TreeNode(2);
  h->right = new TreeNode(3);
  int res = slu.sumNumbers(h);
  cout << res<<endl;
  system("pause");
}