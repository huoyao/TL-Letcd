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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return NULL;
    ListNode *pt = head;
    while (pt->next)
    {
      if (pt->next->val == pt->val)
        pt->next = pt->next->next;
      else
        pt = pt->next;
    }
    return head;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1), *p = h;
  p->next = new ListNode(1);
  ListNode *res = slu.deleteDuplicates(h);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }
    
  system("pause");
}