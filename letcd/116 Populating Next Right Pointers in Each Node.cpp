#if 0
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
  void connect(TreeLinkNode *root) {
    if (!root) return;
    TreeNode *pre = root, *cur = NULL;
    while (pre->left)
    {
      cur = pre;
      while (cur)
      {
        cur->left->next = cur->right;
        if(cur->next) cur->right->next = cur->next->left;
        cur = cur->next;
      }
      pre = pre->left;
    }
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
#endif
