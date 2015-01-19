#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build(vector<int> &postorder, vector<int> &inorder, TreeNode **head, int beg1, int end1, int beg2, int end2)
{
  *head = new TreeNode(postorder[end1]);
  int tag = postorder[end1];
  int i = beg2;
  for (; i <= end2; ++i)
  if (tag == inorder[i]) break;
  int len = end2 - i;
  if (len > 0) build(postorder, inorder, &((*head)->right), end1-len, end1-1, i+1,end2);
  if (i > beg2) build(postorder, inorder, &((*head)->left), beg1, end1-len-1, beg2, i-1);
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *head = NULL;
    if (inorder.size() == 0) return head;
    build(postorder, inorder, &head, 0, postorder.size() - 1, 0, inorder.size() - 1);
    return head;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 4, 5, 1, 3, 2 }, target = { 4, 1, 5, 2, 3 };
  TreeNode * res = slu.buildTree( target,input);
  cout << endl;
  system("pause");
}