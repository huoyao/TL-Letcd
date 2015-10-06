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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    int lena = 0, lenb = 0;
    ListNode *pa = headA, *pb = headB;
    while (pa && pb)
    {
      if (pa->val == pb->val) return pa;
      ++lena; pa = pa->next;
      ++lenb; pb = pb->next;
    }
    while (pa) { ++lena; pa = pa->next; }
    while (pb) { ++lenb; pb = pb->next; }
    int ex = abs(lena - lenb);
    pa = headA;
    pb = headB;
    if (lena > lenb)
      while (ex--) pa = pa->next;
    if (lenb > lena)
      while (ex--) pb = pb->next;
    while (pa && pa->val != pb->val) { pa = pa->next; pb = pb->next; }
    return pa;
  }
};

int main()
{
  Solution slu;
  ListNode *h1 = new ListNode(1);
  ListNode *h2 = new ListNode(2);
  ListNode *h3 = new ListNode(3);
  h1->next = h3;
  h2->next = h3;
  ListNode *res = slu.getIntersectionNode(h1, h2);
  cout << res->val << endl;
  system("pause");
  return 0;
}
#endif
