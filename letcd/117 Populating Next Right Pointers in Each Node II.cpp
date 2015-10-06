#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *nextHead = new TreeLinkNode(0);
    nextHead->next = root;
    while (nextHead->next){
      TreeLinkNode *tail = nextHead,*nxt = nextHead->next;
      nextHead->next = NULL;
      for (; nxt; nxt = nxt->next){
        if (nxt->left){
          tail->next = nxt->left;
          tail = tail->next;
        }
        if (nxt->right){
          tail->next = nxt->right;
          tail = tail->next;
        }
      }
    }
  }
};

int main()
{
  Solution slu;
  TreeLinkNode *h = new TreeLinkNode(2);
  h->left = new TreeLinkNode(1);
  h->right = new TreeLinkNode(3);
  slu.connect(h);
  cout << endl;
  system("pause");
}
#endif
