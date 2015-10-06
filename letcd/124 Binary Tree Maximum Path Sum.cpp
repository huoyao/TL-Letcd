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
private:
  int maxsum = INT_MIN;
public:
  int maxPathSum(TreeNode *root) {
    pathSum(root);
    return maxsum;
  }
  int pathSum(TreeNode *root)
  {
    if (!root) return 0;
    int val = root->val;
    int left = pathSum(root->left);
    int right = pathSum(root->right);
    val += left > 0 ? left : 0;
    val += right > 0 ? right : 0;
    if (val > maxsum) maxsum = val;
    if (left > right && left > 0) return root->val + left;
    if (left<right && right>0) return root->val + right;
    return root->val;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(3);
  int res = slu.maxPathSum(h);
  cout << res << endl;
  system("pause");
}
#endif
