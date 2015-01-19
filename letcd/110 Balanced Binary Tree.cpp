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

class Solution {
private:
  bool balance = true;
public:
  int ht(TreeNode *root)
  {
    if (!balance || !root) return 0;
    int left = ht(root->left) + 1;
    int right = ht(root->right) + 1;
    if (abs(left - right) > 1) { balance = false; return 0; }
    return max(left,right);
  }
  bool isBalanced(TreeNode *root) {
    ht(root);
    return balance;
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  bool res = slu.isBalanced(h);
  cout << res<<endl;
  system("pause");
}