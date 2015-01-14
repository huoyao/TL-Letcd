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
    ListNode **curnext = &head, *cur = head;
    while (cur)
    {
      ListNode *tmp=cur;
      while (cur->next && cur->next->val == cur->val)
        cur = cur->next;
      if (tmp == cur)
      {
        *curnext = tmp;
        curnext = &(*curnext)->next;
      }
      cur = cur->next;
    }
    *curnext = NULL;
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
    cout << res->val << endl;
  system("pause");
}