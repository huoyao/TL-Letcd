#if 0
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
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode *> st;
    TreeNode *ptr=root;
    while(ptr) { st.push(ptr);ptr=ptr->left; }
    while(!st.empty())
    {
      TreeNode *tmp = st.top();
      st.pop();
      --k;
      if(k == 0) return tmp->val;
      if(tmp->right)
      {
        tmp = tmp->right;
        while(tmp) { st.push(tmp);tmp = tmp->left; }
      }
    }
    return -1;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(3);
  int res = slu.kthSmallest(h, 3);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
