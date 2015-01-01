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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *lstres =NULL;
    ListNode *lstid = NULL;
    ListNode *pt1=l1, *pt2=l2;
    int forward = 0;
    while (pt1 && pt2)
    {
      int t = pt1->val + pt2->val+forward;
      if (!lstres)
      {
        lstres = new ListNode(t%10);
        lstid = lstres;
      }
      else
      {
        lstid->next = new ListNode(t%10);
        lstid = lstid->next;
      }
      pt1 = pt1->next;
      pt2 = pt2->next;
      forward = t/10;
    }
    while (pt1)
    {
      int t = pt1->val + forward;
      lstid->next = new ListNode(t % 10);
      lstid = lstid->next;
      pt1 = pt1->next;
      forward = t / 10;
    }
    while (pt2)
    {
      int t = pt2->val + forward;
      lstid->next = new ListNode(t % 10);
      lstid = lstid->next;
      pt2 = pt2->next;
      forward = t / 10;
    }
    if (forward)
      lstid->next = new ListNode(forward);
    return lstres;
  }
};

int main()
{
  Solution slu;
  ListNode *l1 = new ListNode(5);
  ListNode *pt = l1;
  int cnt = 3;
  while (cnt--)
  {
    pt->next= new ListNode(cnt);
    pt = pt->next;
  }
  pt = l1;
  while (pt)
  {
    cout << pt->val << "  " << endl;
    pt = pt->next;
  }
  ListNode *l2 = new ListNode(9);
  ListNode *lstres = slu.addTwoNumbers(l1, l2);
  while (lstres)
  {
    cout << lstres->val << "  " << endl;
    lstres = lstres->next;
  }
  
  system("pause");
}