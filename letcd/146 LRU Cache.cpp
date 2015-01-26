#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

struct cacheNode{
  int key, val;
  cacheNode(const int &x, const  int &y) :key(x), val(y){}
};

class LRUCache{
private:
  int size;
  list<cacheNode> cacheList;
  unordered_map<int, list<cacheNode>::iterator> cacheMap;
public:
  LRUCache(int capacity) {
    size = capacity;
  }

  int get(int key) {
    if (cacheMap.count(key))
    {
      auto it = cacheMap[key];
      cacheList.splice(cacheList.begin(), cacheList, it);
      cacheMap[key] = cacheList.begin();
      return cacheList.begin()->val;
    }
    else return -1;
  }

  void set(int key, int value) {
    if (cacheMap.count(key))
    {
      auto it = cacheMap[key];
      it->val = value;
      cacheList.splice(cacheList.begin(), cacheList, it);
      cacheMap[key] = cacheList.begin();
    }
    else
    {
      if (cacheList.size() == size)
      {
        cacheMap.erase(cacheList.back().key);
        cacheList.pop_back();
      }
      cacheList.push_front(cacheNode(key,value));
      cacheMap[key] = cacheList.begin();
    }
  }
};

int main()
{
  LRUCache slu(2);
  slu.set(1, 1);
  slu.set(2, 2);
  slu.set(3, 3);
  cout<<slu.get(1)<<endl;
  cout<<slu.get(2);
  cout << endl;
  system("pause");
}