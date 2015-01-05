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
    ListNode *h = head, *last = head, *p3, *p2,*p1,*res=head,*last_for=NULL;
    int cnt = 0;
    while (last)
    {
      ++cnt;
      last = last->next;
      if (cnt % k == 0)
      {
        p2 = h->next;
        p3 = p2->next;
        h->next = last;
        p2->next = h;
        while (p3 != last)
        {
          p1 = p3->next;
          p3->next = p2;
          p2 = p3;
          p3 = p1;
        }
        if (res==head) res = p2;   //mark
        else last_for->next = p2;
        last_for = h;
        h = last;
      }
    }
    return res;
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