#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *node;
    vector<int> res;
    if (!root) return res;
    st.push(root);
    while (!st.empty())
    {
      node = st.top();
      res.push_back(node->val);
      st.pop();
      if (node->right) st.push(node->right);
      if (node->left) st.push(node->left);
    }
    return res;
  }
};

int main()
{
  Solution slu;
  TreeNode *tr = new TreeNode(1);
  tr->left = new TreeNode(2);
  vector<int> res = slu.preorderTraversal(tr);
  for (auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
}