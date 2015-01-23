#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode *> mapnode;
    queue<UndirectedGraphNode *> qu;
    if (!node) return node;
    qu.push(node);
    while (!qu.empty())
    {
      UndirectedGraphNode *tmp = qu.front();
      qu.pop();
      if (!mapnode.count(tmp))
      {
        UndirectedGraphNode *newnode = new UndirectedGraphNode(tmp->label);
        mapnode[tmp] = newnode;
      }
      for (int i = tmp->neighbors.size() - 1; i >= 0; --i)
      {
        UndirectedGraphNode *childnode = tmp->neighbors[i];
        if (!mapnode.count(childnode))
        {
          UndirectedGraphNode *newnode = new UndirectedGraphNode(childnode->label);
          mapnode[childnode] = newnode;
          qu.push(childnode);
        }
        mapnode[tmp]->neighbors.push_back(mapnode[childnode]);
      }
    }
    return mapnode[node];
  }
};

int main()
{
  Solution slu;
  UndirectedGraphNode *input = new UndirectedGraphNode(0);
  UndirectedGraphNode *input1 = new UndirectedGraphNode(1);
  UndirectedGraphNode *input2 = new UndirectedGraphNode(2);
  input->neighbors.push_back(input1);
  input->neighbors.push_back(input2);
  input1->neighbors.push_back(input2);
  input2->neighbors.push_back(input2);
  UndirectedGraphNode *res = slu.cloneGraph(input);
  cout << endl;
  system("pause");
}