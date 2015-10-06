#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n <= 0) return head;
    ListNode *lptr=head, *rptr=head,*ptr=NULL,*ptrpre=NULL;
    for (int i = 1; i<n; ++i) rptr = rptr->next;
    while (rptr)
    {
      rptr = rptr->next;
      ptrpre = ptr;
      ptr = lptr;
      lptr = lptr->next;
    }
    if (ptrpre) { ptrpre->next = lptr; delete(ptr); return head; }
    else { delete(ptr); return lptr; }
  }
};

int main()
{
  Solution slu;
  ListNode *head = NULL;
  head = new ListNode(1);
  ListNode *pt = head;
  int cnt = 5;
  while (cnt--)
  {
    pt->next = new ListNode(cnt);
    pt = pt->next;
  }
  pt = slu.removeNthFromEnd(head, 6);
  while (pt)
  {
    cout << pt->val << "  ";
    pt = pt->next;
  }
  system("pause");
}
#endif
