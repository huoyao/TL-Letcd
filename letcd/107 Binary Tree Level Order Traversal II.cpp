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

void levelorder(vector<TreeNode *> &rec,stack<vector<int> > &stk)
{
  while (rec.size())
  {
    vector<int> tmp;
    vector<TreeNode *> rec1;
    for (int i = 0; i < rec.size(); ++i)
    {
      tmp.push_back(rec[i]->val);
      if (rec[i]->left) rec1.push_back(rec[i]->left);
      if (rec[i]->right) rec1.push_back(rec[i]->right);
    }
    stk.push(tmp);
    rec = rec1;
  }
}

class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    stack<vector<int> > stk;
    vector<TreeNode *> rec;
    if (!root) return res;
    else rec.push_back(root);
    levelorder(rec,stk);
    while (!stk.empty())
    {
      vector<int> tmp = stk.top();
      res.push_back(tmp);
      stk.pop();
    }
    return res;
  } 
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->right = new TreeNode(3);
  vector<vector<int> > res = slu.levelOrderBottom(h);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}