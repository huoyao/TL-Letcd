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

void build(RandomListNode *&target, RandomListNode *pt, unordered_map<RandomListNode *, RandomListNode *> &mapnode)
{
  target = new RandomListNode(pt->label);
  mapnode[pt] = target;
  RandomListNode *p = pt,*pp=target;
  while (p->random)
  {
    if (mapnode.count(p->random)) { pp->random = mapnode[p->random]; return; }
    pp->random = new RandomListNode(p->random->label);
    mapnode[p->random] = pp->random;
    pp = pp->random;
    p = p->random;
  }
}

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *res=NULL;
    unordered_map<RandomListNode *, RandomListNode *> mapnode;
    if (!head) return res;
    while (head)
    {
      if (res == NULL) build(res,head,mapnode);
      while (head->next && mapnode.count(head->next)) { mapnode[head]->next = mapnode[head->next]; head = head->next;}
      if (head->next) {build(mapnode[head]->next, head->next, mapnode); head - head->next;}
      else break;
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