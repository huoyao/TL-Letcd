#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void link(TreeLinkNode *&pt, TreeLinkNode *root)
  {
    TreeLinkNode *tmp=root;
    while (tmp)
    {
      if (tmp->left) { pt->next = tmp->left; return; }
      if (tmp->right) { pt->next = tmp->right; return; }
      tmp = tmp->next;
    }
  }
  void connect(TreeLinkNode *root) {
    if (!root) return;
    if (root->left)
    {
      root->left->next = root->right;
      if (!root->right) link(root->left,root->next);
    }
    if (root->right)
    {
      link(root->right, root->next);
    }
    connect(root->right);
    connect(root->left);
  }
};

int main()
{
  Solution slu;
  TreeLinkNode *h = new TreeLinkNode(2);
  h->left = new TreeLinkNode(1);
  h->right = new TreeLinkNode(3);
  slu.connect(h);
  cout << endl;
  system("pause");
}