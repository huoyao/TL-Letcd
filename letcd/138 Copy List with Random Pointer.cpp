#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *res=NULL,*node=head,*tmp;
    if (!head) return res;
    while (node)
    {
      tmp = node->next;
      node->next = new RandomListNode(node->label);
      node->next->next = tmp;
      node = tmp;
    }
    node = head;
    while (node)
    {
      if (node->random) node->next->random = node->random->next;
      node = node->next->next;
    }
    node = head;
    res = node->next;
    tmp = res;
    while (node)
    {
      node->next = tmp->next;
      node = node->next;
      if (node) tmp->next = node->next;
      tmp = tmp->next;
    }
    return res;
  }
};

int main()
{
  Solution slu;
  RandomListNode *h = new RandomListNode(1);
  RandomListNode *h1 = new RandomListNode(2);
  RandomListNode *h2 = new RandomListNode(3);
  h->next = h1;
  h1->next = h2;
  h1->random = h1;
  h2->random = h1;
  RandomListNode *res = slu.copyRandomList(h);
  cout << endl;
  system("pause");
}