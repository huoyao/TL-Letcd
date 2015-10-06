#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) : _capacity(capacity) {}
  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;
    touch(it);
    return it->second.first;
  }
  void set(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) touch(it);
    else {
      if (cache.size() == _capacity) {
        cache.erase(used.back());
        used.pop_back();
      }
      used.push_front(key);
    }
    cache[key] = { value, used.begin() };
  }
private:
  typedef list<int> LI;
  typedef pair<int, LI::iterator> PII;
  typedef unordered_map<int, PII> HIPII;
  HIPII cache;
  LI used;
  int _capacity;
  void touch(HIPII::iterator it) {
    int key = it->first;
    used.erase(it->second.second);
    used.push_front(key);
    it->second.second = used.begin();
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
#endif
