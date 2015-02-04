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

bool cmp(const ListNode *l, const ListNode *r)
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
    make_heap(lists.begin(), lists.end(), cmp);
    ListNode *head = new ListNode(0), *cur = head, *nxt = NULL;
    while (lists.size() > 0)
    {
      cur = cur->next = lists[0];
      pop_heap(lists.begin(), lists.end(), cmp);
      int last = lists.size() - 1;
      nxt = lists[last]->next;
      while (nxt && nxt->val < lists[0]->val) { cur = cur->next = nxt; nxt = nxt->next; }
      if (nxt)
      {
        lists[last] = nxt;
        push_heap(lists.begin(), lists.end(), cmp);
      }
      else lists.pop_back();
    }
    return head->next;
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