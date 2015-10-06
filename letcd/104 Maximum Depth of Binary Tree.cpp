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
  int dep;
public:
  int maxDepth(TreeNode *root) {
    dep = 0;
    depth(root,1);
    return dep;
  }
  void depth(TreeNode *root, int level)
  {
    if (!root) return;
    if (level > dep) dep = level;
    if (root->left) depth(root->left, level + 1);
    if (root->right) depth(root->right, level + 1);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->right = new TreeNode(1);
 int res = slu.maxDepth(h);
  cout << res<<endl;
  system("pause");
}
#endif
