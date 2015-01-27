/*
Given a binary tree where all the right nodes are either leaf nodes
with a sibling(a left node that shares the same parent node) or empty,
flip it upside down and turn it into a tree where the original right
nodes turned into left leaf nodes.Return the new root.
For example :
Given a binary tree{ 1, 2, 3, 4, 5 },
1
/ \
2   3
/ \
4   5
return the root of the binary tree[4, 5, 2, #, #, 3, 1].
4
/ \
5   2
/ \
3   1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* UpsideDownBinaryTree(TreeNode *root) {
    TreeNode *cur = root, *next = NULL, *pre = NULL, *tmp = NULL;
    while (cur)
    {
      next = cur->left;
      cur->left = tmp;
      tmp = cur->right;
      cur->right = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(3);
  TreeNode *res = slu.UpsideDownBinaryTree(h);
  system("pause");
  return 0;
}