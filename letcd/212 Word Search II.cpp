#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Tie
{
  bool is_end;
  int idx;
  Tie *child[26];
  Tie():is_end(false), idx(-1)
  {
    fill_n(child, 26, nullptr);
  }
};

class Solution
{
public:
  void insert(Tie *ptr,const string&words,const int&k)
  {
    for(size_t i = 0;i < words.length();++i)
    {
      int id = words[i] - 'a';
      if(!ptr->child[id]) ptr->child[id] = new Tie();
      ptr = ptr->child[id];
    }
    ptr->idx = k;
    ptr->is_end = true;
  }
  Tie * buildTie(const vector<string>& words)
  {
    Tie *rt = new Tie();
    for(size_t i = 0;i < words.size();++i) insert(rt, words[i],i);
    return rt;
  }
  void find(const int &i, const int &j, vector<vector<char>>& board, const vector<string>& words,Tie *root)
  {
    char bak = board[i][j];
    int id = bak - 'a';
    if(board[i][j] == '0') return;
    else if(root->child[id] == NULL) return;
    else
    {
      if(root->child[id]->is_end)
      {
        res.push_back(words[root->child[id]->idx]);
        root->child[id]->is_end = false;
      }
      board[i][j] = '0';
      if(i > 0) find(i - 1, j, board, words, root->child[id]);
      if(i < row-1) find(i + 1, j, board, words, root->child[id]);
      if(j > 0) find(i, j-1, board, words, root->child[id]);
      if(j < col-1) find(i , j+1, board, words, root->child[id]);
      board[i][j] = bak;
    }
  }
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    row = board.size();
    col = row ? board[0].size() : 0;
    words_num = words.size();
    if(row == 0 || col == 0 || words_num == 0) return res;
    root = buildTie(words);
    for(size_t i = 0;i < row;++i)
    {
      for(size_t j = 0;j < col;++j) find(i, j, board, words,root);
    }
    return res;
  }
private:
  int row, col,words_num;
  vector<string> res;
  Tie *root;
};

int main()
{
  Solution slu;
  vector<vector<char>> input = { { 'o', 'a', 'a', 'n' },
  { 'e', 't', 'a', 'e' },
  { 'i', 'h', 'k', 'r' },
  { 'i', 'f', 'l', 'v' } };
  vector<string> target = { "oath", "pea", "eat", "rain" };
  vector<string> res = slu.findWords(input, target);
  for(auto &t : res)
    cout << t << "  ";
  cout << endl;
  system("pause");
  return 0;
}