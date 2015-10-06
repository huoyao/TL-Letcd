#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *root = new ListNode(-1),*ptr=root,*tmp;
    ptr->next = head;
    while(ptr->next)
    {
      if(ptr->next->val == val)
      {
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      } else ptr = ptr->next;
    }
    return root->next;
  }
};

int main()
{
  Solution slu;
  ListNode *head = new ListNode(1),*p=head;
  p->next = new ListNode(1);
  p = p->next;
  p->next = new ListNode(2);
  int target = 1;
  ListNode* res = slu.removeElements(head,target);
  while(res)
  {
    cout << res->val<<" ";
    res = res->next;
  }
  cout << endl;
  system("pause");
  return 0;
}
#endif
