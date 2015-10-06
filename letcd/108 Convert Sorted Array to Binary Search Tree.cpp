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
public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    TreeNode *h=NULL;
    if (num.size() == 0) return h;
    build(num,&h,0,num.size()-1);
    return h;
  }
  void build(const vector<int> &num, TreeNode **h, const int beg, const int end)
  {
    if (beg > end) return;
    int mid = (beg + end) >> 1;
    *h = new TreeNode(num[mid]);
    build(num, &((*h)->left), beg, mid - 1);
    build(num, &((*h)->right), mid + 1, end);
  }
};

int main()
{
  Solution slu;
  vector<int> input = { 2, 7, 11, 15 };
  TreeNode *res = slu.sortedArrayToBST(input);
  cout << endl;
  system("pause");
}
#endif
