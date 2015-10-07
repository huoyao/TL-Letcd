#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    if(board.size() == 0 || word == "") return false;
    for(int i = 0; i < board.size(); ++i)
      for(int j = 0; j < board[i].size(); ++j)
        if(find(i, j, word, board, 0)) return true;
    return false;
  }
  bool find(const int &i, const int &j, const string &wd, vector<vector<char> > &board, int k) {
    if(board[i][j] != wd[k]) return false;
    if(k == wd.size() - 1) return true;
    char tmp = board[i][j];
    board[i][j] = '*';
    if(i + 1 < board.size() && find(i + 1, j, wd, board, k + 1)) return true;
    if(i > 0 && find(i - 1, j, wd, board, k + 1)) return true;;
    if(j > 0 && find(i, j - 1, wd, board, k + 1)) return true;
    if(j + 1 < board[i].size() && find(i, j + 1, wd, board, k + 1)) return true;
    board[i][j] = tmp;
    return false;
  }
};

int main() {
  Solution slu;
  vector<vector<char> > input = { { 'a', 'b', 'c', 'd' }, { 'a', 'b', 't', 'r' } };
  string target = "c";
  bool res = slu.exist(input, target);
  cout << res << endl;
  system("pause");
}
#endif
