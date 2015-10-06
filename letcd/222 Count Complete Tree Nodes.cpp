#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  int countNodes(TreeNode* root) {
    int height = 0;
    TreeNode *p = root;
    while(p) { p = p->left;++height; }
    return calNodes(root,height-1);
  }
  int calNodes(const TreeNode *root, const int &h)
  {
    if(!root) return 0;
    int left_h = getMostLeft(root->right);
    if(h == left_h)
      return (1 << h) + calNodes(root->right, left_h - 1);
    else
      return (1 << left_h) + calNodes(root->left, h - 1);
  }
  int getMostLeft(TreeNode *root)
  {
    TreeNode *p = root;
    int h = 0;
    while(p) { p = p->left;++h; }
    return h;
  }
};

int main()
{
  TreeNode *head = new TreeNode(1);
  TreeNode *p = head;
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);
  TreeNode *p1 = p->right;
  p = p->left;
  p->left = new TreeNode(4);
  p->right = new TreeNode(5);
  p1->left = new TreeNode(6);
  p1->right = new TreeNode(7);
  p1 = p->right;
  p = p->left;
  p->left = new TreeNode(8);
  p->right = new TreeNode(9);
  p1->left = new TreeNode(10);
  Solution slu;
  int res = slu.countNodes(head);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
