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
  ListNode *partition(ListNode *head, int x) {
    ListNode *h = NULL, *hlast = NULL, *phead = NULL, *pt = new ListNode(-1);
    pt->next = head;
    while (pt->next)
    {
      if (pt->next->val >= x)
      {
        if (!phead) phead = pt->next;
        pt = pt->next;
      }
      else
      {
        if (!h) { h = pt->next; hlast = pt->next; }
        else {  hlast->next = pt->next; hlast = hlast->next;}
        pt->next = pt->next->next;
      }
    }
    if (hlast) hlast->next = phead;
    else h = phead;
    return h;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(3);
  h->next = new ListNode(1);
  ListNode *p = h->next;
  p->next = new ListNode(2);
  int target = 2;
  ListNode *res = slu.partition(h, target);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }
  system("pause");
}