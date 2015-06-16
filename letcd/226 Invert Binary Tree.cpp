#include <iostream>
#include <vector>
#include <stack>
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
  TreeNode* invertTree(TreeNode* root) {
    return inverTree_(root);
    if(!root || !root->left&&!root->right) return root;
    TreeNode *tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
    return root;
  }
  TreeNode *inverTree_(TreeNode *root)
  {
    if(!root) return root;
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty())
    {
      TreeNode *p = st.top();
      st.pop();
      swap(p->left, p->right);
      if(p->left) st.push(p->left);
      if(p->right) st.push(p->right);
    }
    return root;
  }
};

void print(TreeNode *res)
{
  if(!res) return;
  cout << res->val << endl;
  print(res->left);
  print(res->right);
}

int main()
{
  Solution slu;
  TreeNode *root=new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  TreeNode *tmp = root->left;
  tmp->left = new TreeNode(3);
  TreeNode *res = slu.invertTree(root);
  print(res);
  cout << endl;
  system("pause");
  return 0;
}