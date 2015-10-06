#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
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
  deque<TreeNode *> path;
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    const int &val_p = p->val,&val_q=q->val;
    inputParent(root, p);
    return outputParent(root, q);
  }
  void inputParent(TreeNode *root,TreeNode *p)
  {
    TreeNode *ptr = root;
    while(ptr != p)
    {
      path.push_back(ptr);
      if(p->val <= ptr->val) ptr = ptr->left;
      else ptr = ptr->right;
    }
    path.push_back(ptr);
  }
  TreeNode * outputParent(TreeNode *root,TreeNode * q)
  {
    TreeNode *ptr = root;
    deque<TreeNode *>::iterator it = path.begin();
    while(it!=path.end() && ptr == *it)
    {
      if(ptr == q) return q;
      if(q->val <= ptr->val) ptr = ptr->left;
      else ptr = ptr->right;
      ++it;
    }
    return *(--it);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(3);
  TreeNode *res = slu.lowestCommonAncestor(h, h, h->right);
  cout << res->val << endl;
  return 0;
}
#endif
