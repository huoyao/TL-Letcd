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

vector<TreeNode *> build(int start,int end)
{
  vector<TreeNode *> res;
  if (start > end)
  {
    res.push_back(NULL);
    return res;
  }
  for (int k = start; k <= end; ++k)
  {
    vector<TreeNode *> left = build(start,k-1);
    vector<TreeNode *> right = build(k+1,end);
    for (int i = 0; i < left.size(); ++i)
    {
      for (int j = 0; j < right.size(); ++j)
      {
        TreeNode *root = new TreeNode(k);
        root->left = left[i];
        root->right = right[j];
        res.push_back(root);
      }
    }
  }
  return res;
}

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    return build(1,n);
  }
};

int main()
{
  Solution slu;
  int input = 3;
  vector<TreeNode *> res = slu.generateTrees(input);
  cout <<res.size()<< endl;
  system("pause");
}