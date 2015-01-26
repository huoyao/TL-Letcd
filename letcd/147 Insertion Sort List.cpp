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
  ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *phead = head,*pt=head->next,*pnext,*pidx,*pval;
    phead->next = NULL;
    while (pt)
    {
      pnext = pt->next;
      pidx = phead;
      pval = NULL;
      pt->next = NULL;
      while (pidx && pidx->val < pt->val) { pval = pidx; pidx = pidx->next; }
      pt->next = pidx;
      if (pval) pval->next = pt;
      else phead = pt;
      pt = pnext;
    }
    return phead;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(2);
  h->next = new ListNode(1);
  ListNode *p = h->next;
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(3);
  p = p->next;
  p->next = new ListNode(5);
  ListNode *hp=slu.insertionSortList(h);
  while (hp)
  {
    cout << hp->val << "  ";
    hp = hp->next;
  }
  cout << endl;
  system("pause");
}