#if 0
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) return NULL;
    int pre = 0, pin = 0;
    TreeNode *head = new TreeNode(preorder[pre++]), *pt = NULL;
    stack<TreeNode *> roots;
    roots.push(head);
    while (true)
    {
      if (inorder[pin] == roots.top()->val)
      {
        pt = roots.top();
        roots.pop();
        ++pin;
        if (pin == inorder.size()) break;
        if (!roots.empty() && inorder[pin] == roots.top()->val) continue;
        pt->right = new TreeNode(preorder[pre++]);
        roots.push(pt->right);
      }else
      {
        pt = new TreeNode(preorder[pre++]);
        roots.top()->left = pt;
        roots.push(pt);
      }
    }
    return head;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 1, 4, 5, 3 }, target = { 4, 1, 5, 2, 3 };
  TreeNode * res = slu.buildTree(input, target);
  cout << endl;
  system("pause");
}
#endif
