#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
  void deleteNode(ListNode* node) {
    ListNode *nxt = node->next;
    node->val = nxt->val;
    node->next = nxt->next;
    free(nxt);
  }
};

int main()
{
  Solution slu;
  ListNode *root = new ListNode(0);
  root->next = new ListNode(1);
  slu.deleteNode(root->next);
  ListNode *pt = root;
  while(pt)
  {
    cout << pt->val << " ";
  }
  system("pause");
  return 0;
}
#endif
