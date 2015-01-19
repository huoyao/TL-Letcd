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

void build(vector<int> &preorder, vector<int> &inorder,TreeNode **head,int beg1,int end1,int beg2,int end2)
{
  *head = new TreeNode(preorder[beg1]);
  int tag = preorder[beg1];
  int i = beg2;
  for (; i <= end2;++i)
    if (tag == inorder[i]) break;
  int len = i - beg2;
  if (len > 0) build(preorder, inorder, &((*head)->left), beg1+1, beg1+len, beg2,i-1);
  if (i < end2) build(preorder, inorder, &((*head)->right), beg1+len+1,end1, i+1, end2);
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *head=NULL;
    if (preorder.size() == 0) return head;
    build(preorder, inorder, &head, 0, preorder.size() - 1,0, inorder.size() - 1);
    return head;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 1,4,5,3 }, target = {4,1,5,2,3};
  TreeNode * res = slu.buildTree(input, target);
  cout << endl;
  system("pause");
}