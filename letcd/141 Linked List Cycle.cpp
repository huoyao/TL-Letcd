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
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) return true;
    }
    return false;
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
  bool res = slu.hasCycle(h);
  cout << res << endl;
  system("pause");
}