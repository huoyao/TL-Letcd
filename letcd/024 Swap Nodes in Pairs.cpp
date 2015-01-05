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
    ListNode *p1=NULL, *p2=head, *p3=NULL,*h=NULL;
    if (!p2 || !p2->next) return head;
    p3 = p2->next;
    while (p3)
    {
      p2->next = p3->next;
      p3->next = p2;
      if (p1) p1->next = p3;
      if (!h) h = p3;
      p1 = p2;
      if (!p2->next) return h;
      else p2 = p2->next;
      if (!p2->next) return h;
      else p3 = p2->next;
    }
    return h;
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