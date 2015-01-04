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
    int cnt = 0;
    ListNode *lptr=head, *rptr=head;
    while (rptr)
    {
      rptr = rptr->next;
      if (cnt > n) lptr = lptr->next;
      ++cnt;
    }
    if (n > cnt) return head;
    ListNode *pt = lptr->next;
    if (n == cnt) {
      head->next = NULL;
      delete(head);
      return pt;
    }
    if (!pt) return NULL;
    lptr->next = pt->next;
    pt->next = NULL;
    delete(pt);
    return head;
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