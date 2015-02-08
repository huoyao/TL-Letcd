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

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    TreeNode *res = NULL;
    if (!head) return res;
    ListNode *end = head;
    int cnt = 1;
    while (end->next) { end = end->next; ++cnt; }
    build(head,cnt,&res);
    return res;
  }
  void build(ListNode *beg, int cnt, TreeNode **h)
  {
    if (cnt <= 0 || !beg) return;
    int mid = cnt >> 1, idx = mid;
    ListNode *beg1 = beg;
    while (idx--) beg1 = beg1->next;
    *h = new TreeNode(beg1->val);
    build(beg, mid, &((*h)->left));
    build(beg1->next, cnt - mid - 1, &((*h)->right));
  }
};

int main()
{
  Solution slu;
  ListNode *h = new ListNode(-10);
  h->next = new ListNode(-3);
  ListNode *pt = h->next;
  pt->next = new ListNode(0);
  pt = pt->next;
  pt->next = new ListNode(5);
  pt = pt->next;
  pt->next = new ListNode(9);
  TreeNode *res = slu.sortedListToBST(h);
  cout << endl;
  system("pause");
}