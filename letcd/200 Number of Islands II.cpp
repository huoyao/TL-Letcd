#if 0
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class Solution
{
public:
  /**
  * @param n an integer
  * @param m an integer
  * @param operators an array of point
  * @return an integer array
  */
  class UnionFindSet
  {
  private:
    int *pre;
  public:
    UnionFindSet(const int&num)
    {
      pre =(int *) malloc(sizeof(int)*num);
      init(num);
    }
    void init(const int&num)
    {
      for(size_t i = 0;i < num;++i) pre[i] = i;
    }
    void unionOp(const int &a,const int &b)
    {
      if(pre[a] != pre[b]) pre[pre[a]] = pre[b];
    }
    int find(const int &x)
    {
      if(pre[x] != x) pre[x] = find(pre[x]);
      return pre[x];
    }
    ~UnionFindSet()
    {
      free(pre);
    }
  };
  int cnt = 0;
  vector<int> numIslands2(int n, int m, vector<Point>& operators) {
    vector<int> res;
    if(n < 1 || m < 1 || operators.size() < 1) return res;
    bool *is_island = (bool *)malloc(sizeof(bool)*n*m);
    memset(is_island, 0, sizeof(bool)*n*m);
    UnionFindSet uf_set(n*m);
    for(size_t i = 0;i < operators.size();++i)
    {
      const int &id_x = operators[i].x, &id_y = operators[i].y;
      const int &id = id_x*m + id_y;
      if(is_island[id]) { res.push_back(cnt);continue; }
      is_island[id] = true;
      ++cnt;
      if(id_y>0 && is_island[id-1]) check(id, id - 1,uf_set);
      if(id_y < m - 1 && is_island[id + 1]) check(id, id + 1, uf_set);
      if(id_x>0 && is_island[id - m]) check(id, id - m, uf_set);
      if(id_x < n - 1 && is_island[id + m]) check(id, id + m, uf_set);
      res.push_back(cnt);
    }
    free(is_island);
    return res;
  }
  void check(const int &idx,const int&idy,UnionFindSet&st)
  {
    if(st.find(idx) == st.find(idy)) return;
    else
    {
      st.unionOp(idx, idy);
      --cnt;
    }
  }
};

int main()
{
  Solution slu;
  int n = 4, m = 5;
  vector<Point> input = { { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, {1,1} };
  vector<int> res = slu.numIslands2(n,m,input);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}
#endif
