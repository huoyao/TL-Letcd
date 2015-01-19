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
  int mindep = INT_MAX;
public:
  void mindp(TreeNode *root,int level)
  {
    if (!root->left && !root->right)
    {
      mindep = min(mindep, level);
      return;
    }
    if(root->left) mindp(root->left,level+1);
    if(root->right) mindp(root->right,level+1);
  }
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    mindp(root,1);
    return mindep;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  int res = slu.minDepth(h);
  cout << res<<endl;
  system("pause");
}