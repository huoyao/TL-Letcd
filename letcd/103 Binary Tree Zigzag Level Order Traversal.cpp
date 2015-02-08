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
  vector<vector<int> > res;
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<TreeNode *> v1, v2;
    if (!root) return res;
    v1.push_back(root);
    while (v1.size() || v2.size())
    {
      v2.clear();
      scan(v1, v2);
      v1.clear();
      scan(v2, v1);
    }
    return res;
  }
  void scan(vector<TreeNode *> &v1, vector<TreeNode *> &v2)
  {
    vector<int> rec;
    if (v1.size() == 0) return;
    for (int i = v1.size() - 1, j = 0; i >= 0; --i, ++j)
    {
      rec.push_back(v1[j]->val);
      if (res.size() % 2 == 0)
      {
        if (v1[i]->right) v2.push_back(v1[i]->right);
        if (v1[i]->left) v2.push_back(v1[i]->left);
      }
      else
      {
        if (v1[i]->left) v2.push_back(v1[i]->left);
        if (v1[i]->right) v2.push_back(v1[i]->right);
      }
    }
    res.push_back(rec);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(3);
  h->right = new TreeNode(1);
  vector<vector<int> > res = slu.zigzagLevelOrder(h);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}