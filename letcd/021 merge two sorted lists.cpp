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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *pt1 = l1, *pt2 = l2, *head = l1->val < l2->val ? l1 : l2 , *pt = head;
    if (l1->val < l2->val) { head = l1; pt1 = pt1->next; }
    else { head = l2; pt2 = pt2->next; }
    while (pt1 && pt2)
    {
      if (pt1->val < pt2->val) {
        pt->next = pt1;
        pt1 = pt1->next;
      }
      else
      {
        pt->next = pt2;
        pt2 = pt2->next;
      }
      pt = pt->next;
    }
    if (!pt1) pt->next = pt2;
    if (!pt2) pt->next = pt1;
    return head;
  }
};

int main()
{
  Solution slu;
  ListNode *l1 = new ListNode(2), *l2 = new ListNode(1);
  ListNode *res = slu.mergeTwoLists(l1, l2);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }
  system("pause");
}

#endif
