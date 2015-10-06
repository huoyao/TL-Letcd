#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0) return NULL;
    int pst = postorder.size() - 1, pin = inorder.size() - 1;
    TreeNode *head = new TreeNode(postorder[pst--]), *pt = NULL;
    stack<TreeNode *> roots;
    roots.push(head);
    while (true)
    {
      if (inorder[pin] == roots.top()->val)
      {
        pt = roots.top();
        roots.pop();
        --pin;
        if (pin < 0)break;
        if (!roots.empty() && inorder[pin] == roots.top()->val) continue;
        pt->left = new TreeNode(postorder[pst--]);
        roots.push(pt->left);
      }else
      {
        pt = new TreeNode(postorder[pst--]);
        roots.top()->right = pt;
        roots.push(pt);
      }
    }
    return head;
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 4, 5, 1, 3, 2 }, target = { 4, 1, 5, 2, 3 };
  TreeNode * res = slu.buildTree(target, input);
  cout << endl;
  system("pause");
}
#endif
