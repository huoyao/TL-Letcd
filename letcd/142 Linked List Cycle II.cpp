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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) 
      {
        slow = head;
        while (slow != fast){ slow = slow->next; fast = fast->next; }
        return slow;
      }
    }
    return NULL;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1);
  h->next = new ListNode(2);
  ListNode *p = h->next;
  p->next = new ListNode(3);
  p = p->next;
  p->next = h->next;
  ListNode *res = slu.detectCycle(h);
  cout << res->val << endl;
  system("pause");
}
#endif
