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
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *h = head, *ptarget = NULL, *pend = head, *phead,*p=head;
    int len = 0;
    while (p){ ++len; p = p->next; }
    if (len == 0) return h;
    k %= len;
    while (--k && pend) { pend = pend->next; }
    if (!pend || !pend->next || k < 0) return h;
    while (pend->next)
    {
      if (!ptarget)
        ptarget = head;
      else
        ptarget = ptarget->next;
      pend = pend->next;
    }
    phead = ptarget->next;
    pend->next = h;
    ptarget->next = NULL;
    return phead;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1);
  h->next = new ListNode(2);
  ListNode *p = h->next;
  p->next = new ListNode(3);
  int target = 1;
  ListNode *res = slu.rotateRight(h, target);
  while (res)
  {
    cout << res->val << "  ";
    res = res->next;
  }
  cout << endl;
  system("pause");
}