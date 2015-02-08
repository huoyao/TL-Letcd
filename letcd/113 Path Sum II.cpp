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
  vector<int> vecrec;
  int rec;
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    if (!root) return res;
    rec = root->val;
    vecrec.push_back(root->val);
    sumpath(root, sum);
    return res;
  }
  void sumpath(TreeNode *rt, const int &sum)
  {
    if (!rt) return;
    if (!rt->left && !rt->right && rec == sum) res.push_back(vecrec);
    TreeNode *tmp = rt->left;
    if (!tmp) tmp = rt->right;
    while (tmp)
    {
      rec += tmp->val;
      vecrec.push_back(tmp->val);
      sumpath(tmp, sum);
      rec -= tmp->val;
      vecrec.pop_back();
      if (tmp == rt->left) tmp = rt->right;
      else break;
    }
  }
};

int main()
{
  Solution slu;
  TreeNode *h = new TreeNode(2);
  h->left = new TreeNode(1);
  h->right = new TreeNode(1);
  vector<vector<int> > res = slu.pathSum(h, 3);
  for (auto &t : res)
  {
    for (auto &k : t)
      cout << k << "  ";
    cout << endl;
  }
  system("pause");
}