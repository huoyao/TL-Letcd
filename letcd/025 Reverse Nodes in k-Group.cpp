#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || !head) return head;
    ListNode *h = new ListNode(0), *pre = h,*prebak=NULL, *cur=NULL,*nxt=NULL,*lastbak=NULL,*last=head;
    h->next = head;
    while (last)
    {
      int cnt=0;
      while (cnt++ < k && last) last = last->next;
      if (cnt <= k) break;
      cur = pre->next;
      prebak = pre->next;
      nxt = cur->next;
      lastbak = last;
      while (cur != last)
      {
        cur->next = lastbak;
        lastbak = cur;
        cur = nxt;
        if(nxt) nxt = nxt->next;
      }
      pre->next = lastbak;
      pre = prebak;
    }
    return h->next;
  }
};

int main()
{
  Solution slu;
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(0);
  l1->next = l2;
  l2->next = new ListNode(3);
  l2 = l2->next;
  l2->next = new ListNode(4);
  ListNode *res = slu.reverseKGroup(l1,2);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }
  system("pause");
}
#endif
