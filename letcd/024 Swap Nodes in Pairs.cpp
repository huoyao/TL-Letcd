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
  ListNode *swapPairs(ListNode *head) {
    ListNode *beg = new ListNode(0);
    beg->next = head;
    for (ListNode *cur = beg; cur->next && cur->next->next; cur = cur->next->next)
      cur->next = swap(cur->next,cur->next->next);
    return beg->next;
  }
  ListNode *swap(ListNode *l1, ListNode *l2)
  {
    l1->next = l2->next;
    l2->next = l1;
    return l2;
  }
};

int main()
{
  Solution slu;
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(0);
  l1->next = l2;
  ListNode *res = slu.swapPairs(l1);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }
  system("pause");
}
#endif
