#if 0
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
  vector<vector<int> > levelOrder(TreeNode *root) {
    levelTra(root,0);
    return res;
  }
  void levelTra(TreeNode *rt, int level)
  {
    if (!rt) return;
    if (level == res.size())
    {
      vector<int> v;
      res.push_back(v);
    }
    res[level].push_back(rt->val);
    levelTra(rt->left, level + 1);
    levelTra(rt->right, level + 1);
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(3);
  h->right = new TreeNode(1);
  vector<vector<int> > res = slu.levelOrder(h);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}
#endif
