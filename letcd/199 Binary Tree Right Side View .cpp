#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
  vector<int> rightSideView(TreeNode* root) {
    TreeNode *p = root;
    search(p, 0);
    return res;
  }
  void search(TreeNode *p,const int &curr_depth)
  {
    if(!p) return;
    if(curr_depth == res.size()) res.push_back(p->val);
    search(p->right,curr_depth+1);
    search(p->left, curr_depth + 1);
  }
private:
  vector<int> res;
};

int main()
{
  Solution slu;
  TreeNode *head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->left->left = new TreeNode(4);
  head->right = new TreeNode(3);
  vector<int> res = slu.rightSideView(head);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
