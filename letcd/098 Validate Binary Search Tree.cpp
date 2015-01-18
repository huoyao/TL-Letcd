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

bool checkValid(TreeNode *root,const int min_e,const int max_e,int &cntmin,int &cntmax)
{
  if (!root) return true;
  if (root->val == INT_MIN) ++cntmin;
  if (root->val == INT_MAX) ++cntmax;
  return (root->val > min_e || min_e==INT_MIN && root->val == INT_MIN && cntmin == 1) && (root->val < max_e || INT_MAX==max_e && root->val == INT_MAX &&cntmax == 1)
    && checkValid(root->left, min_e, root->val,cntmin,cntmax) && checkValid(root->right, root->val, max_e,cntmin,cntmax);
}

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root || !root->left && !root->right) return true;
    int cntmin = 0, cntmax = 0;
    return checkValid(root,INT_MIN,INT_MAX,cntmin,cntmax);
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