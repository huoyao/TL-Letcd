#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next) return;
    ListNode *pmid = head, *pend = head,*phead,*pnext,*pidx;
    while (pend->next && pend->next->next){ pmid = pmid->next; pend = pend->next->next; }
    pidx=phead = pmid->next;
    pend = phead->next;
    pidx->next = NULL;
    pmid->next = NULL;
    while (pend){ pnext = pend->next; pend->next = pidx; pidx = pend; pend = pnext; }
    pend = head;
    while (pend && pidx){ pnext = pidx->next; pidx->next = pend->next; pend->next = pidx; pend = pidx->next; pidx = pnext; }
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1);
  h->next = new ListNode(2);
  ListNode *p = h->next;
  p->next = new ListNode(3);
  p = p->next;
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(5);
  slu.reorderList(h);
  while (h)
  {
    cout << h->val << "  ";
    h = h->next;
  }
  cout << endl;
  system("pause");
}
#endif
