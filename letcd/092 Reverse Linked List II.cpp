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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m == n) return head;
    ListNode *pre = NULL, *last = NULL, *pt = head,*ptnext,*ptlast;
    int idx = 1;
    while (idx < m) 
    {
      if (!pre) pre = head;
      else pre = pre->next;
      ++idx;
    }
    if (pre) { pt = pre->next; pre->next = NULL; }
    ptlast = pt;
    ptnext = pt->next;
    ptlast->next = NULL;
    last = ptnext->next;
    while (idx < n)
    {
      ptnext->next = pt;
      pt = ptnext;
      ptnext = last;
      if(last)last = last->next;
      ++idx;
    }
    ptlast->next = ptnext;
    if (pre) { pre->next = pt; return head; }
    else return pt;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1);
  h->next = new ListNode(2);
  ListNode *p = h->next;
  p->next = new ListNode(3);
  ListNode *res = slu.reverseBetween(h, 1,2);
  while (res)
  {
    cout << res->val;
    res = res->next;
  }
  system("pause");
}