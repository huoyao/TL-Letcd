#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode *l,const ListNode *r)
{
  return l->val > r->val;
}

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *>::iterator it = lists.begin();
    while (it != lists.end())
    {
      if (*it == NULL) lists.erase(it);
      else ++it;
    }
    if (lists.size() == 0) return NULL;
    make_heap(lists.begin(),lists.end(),cmp);
    ListNode *head=NULL, *cur=NULL;
    while (lists.size() > 0)
    {
      if (head == NULL) head = cur = lists[0];
      else cur = cur->next = lists[0];
      pop_heap(lists.begin(), lists.end(), cmp);
      int last = lists.size() - 1;
      if (lists[last]->next != NULL)
      {
        lists[last] = lists[last]->next;
        push_heap(lists.begin(), lists.end(), cmp);
      }
      else lists.pop_back();
    }
    return head;
  }
};

int main()
{
  Solution slu;
  vector<ListNode *> lists;
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(0);
  lists.push_back(l1);
  lists.push_back(l2);
  ListNode *res = slu.mergeKLists(lists);
  while (res)
  {
    cout << res->val << endl;
    res = res->next;
  }

  system("pause");
}