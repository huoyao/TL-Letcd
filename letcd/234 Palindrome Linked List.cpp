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
  bool isPalindrome(ListNode* head) {
    ListNode *ptr_before=NULL,*ptr = head, *ptr_after = head, *ptr_end = head;
    if(ptr_after && ptr_after->next) ptr_after = ptr_after->next;
    else return true;
    while(ptr_end->next && ptr_end->next->next)
    {
      ptr_end = ptr_end->next->next;
      ptr->next = ptr_before;
      ptr_before = ptr;
      ptr = ptr_after;
      ptr_after = ptr_after->next;
    }
    bool is_ok = true;
    if(ptr_end->next) 
    {
      if(ptr->val != ptr_after->val)is_ok = false;
      ptr_end = ptr_after->next;
    }
    else ptr_end = ptr_after;
    if(ptr_before) ptr_after = ptr_before->next; 
    swap(ptr, ptr_before);
    while(ptr)
    {
      if(is_ok && ptr->val != ptr_end->val) is_ok = false;
      ptr_end = ptr_end->next;
      ptr->next = ptr_before;
      ptr_before = ptr;
      ptr = ptr_after;
      if(ptr_after) ptr_after = ptr_after->next;
    }
    return is_ok;
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(1);
  h->next = new ListNode(2);
  //h->next->next = new ListNode(2);
  //h->next->next->next = new ListNode(1);
  bool res = slu.isPalindrome(h);
  cout << res << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
