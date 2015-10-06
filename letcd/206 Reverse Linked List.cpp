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
  ListNode* reverseList(ListNode* head) {
    ListNode *root=NULL;
    while(head)
    {
      ListNode *nxt = head->next;
      head->next = root;
      root = head;
      head = nxt;
    }
    return root;
  }
  ListNode* reverseList_(ListNode* head) {
    return newHead(head,NULL);
  }
  ListNode *newHead(ListNode* head, ListNode* newH)
  {
    if(head == NULL) return newH;
    ListNode *nxt = head->next;
    head->next = newH;
    return newHead(nxt, head);
  }
};
int main()
{
  Solution slu;
  ListNode *head = new ListNode(1), *p = head;
  p->next = new ListNode(2);
  p = p->next;
  p->next = new ListNode(3);
  ListNode *res = slu.reverseList_(head);
  while(res)
  {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  system("pause");
  return 0;
}
#endif
