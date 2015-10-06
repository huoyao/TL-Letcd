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
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    return mergesort(head);
    ListNode *pmid = head, *pend = head;
    while (pend->next && pend->next->next) { pmid = pmid->next; pend = pend->next->next; }
  }
  ListNode *merge(ListNode *l, ListNode *r)
  {
    ListNode *phead = new ListNode(0);
    ListNode *rec = phead;
    while (l && r)
    {
      if (l->val < r->val) { phead->next = l; l = l->next; }
      else { phead->next = r; r = r->next; }
      phead = phead->next;
    }
    if (l) phead->next = l;
    else phead->next = r;
    phead = rec->next;
    delete(rec);
    return phead;
  }
  ListNode * mergesort(ListNode *head)
  {
    if (!head || !head->next) return head;
    ListNode *pmid = head, *pend = head;
    while (pend->next && pend->next->next) { pmid = pmid->next; pend = pend->next->next; }
    pend = pmid->next;
    pmid->next = NULL;
    ListNode *l = mergesort(head), *r = mergesort(pend);
    return merge(l, r);
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
  ListNode *ph=slu.sortList(h);
  while (ph)
  {
    cout << ph->val << "  ";
    ph = ph->next;
  }
  cout << endl;
  system("pause");
}
#endif
