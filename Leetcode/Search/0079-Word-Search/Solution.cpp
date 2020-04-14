
/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <string>
#include <queue>

using std::vector;
using std::string;
using std::queue;

class Solution {
private:
    int m, n;

    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int index) {
        if (index == word.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
            return false;

        char ori = board[i][j];
        board[i][j] = '.';
        bool res = dfs(board, word, i - 1, j, index + 1)
                || dfs(board, word, i, j - 1, index + 1)
                || dfs(board, word, i + 1, j, index + 1)
                || dfs(board, word, i, j + 1, index + 1);
        board[i][j] = ori;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;

        return false;
    }
};