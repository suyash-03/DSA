class Solution {
public:
    bool existsUtil(int i, int j, int m, int n, vector<vector<char>>& board, string word, int index, vector<vector<int>>& visited) {
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[index] || visited[i][j] == 1) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        visited[i][j] = 1;
        bool found = existsUtil(i + 1, j, m, n, board, word, index + 1, visited)
                     || existsUtil(i - 1, j, m, n, board, word, index + 1, visited)
                     || existsUtil(i, j + 1, m, n, board, word, index + 1, visited)
                     || existsUtil(i, j - 1, m, n, board, word, index + 1, visited);
        visited[i][j] = 0; // Backtrack: Mark cell as unvisited again
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<int>> visited(m, vector<int>(n, 0));
                if (existsUtil(i, j, m, n, board, word, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
