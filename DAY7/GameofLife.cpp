class Solution {
public:
    int liveNeighbors(vector<vector<int>>& board, int i, int j, int n, int m) {
        int c = 0;
        // Checking all 8 possible neighbors
        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) c++;  
        if (i - 1 >= 0 && board[i - 1][j] == 1) c++;  
        if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == 1) c++;  
        if (j - 1 >= 0 && board[i][j - 1] == 1) c++;  
        if (j + 1 < m && board[i][j + 1] == 1) c++;  
        if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == 1) c++;  
        if (i + 1 < n && board[i + 1][j] == 1) c++;  
        if (i + 1 < n && j + 1 < m && board[i + 1][j + 1] == 1) c++;  

        return c;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> nextBoard(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveNeighborsCount = liveNeighbors(board, i, j, n, m);

                if (board[i][j] == 1) {
                    if (liveNeighborsCount < 2 || liveNeighborsCount > 3) {
                        nextBoard[i][j] = 0;
                    } else {
                        nextBoard[i][j] = 1;
                    }
                } else {
                   
                    if (liveNeighborsCount == 3) {
                        nextBoard[i][j] = 1;
                    } else {
                        nextBoard[i][j] = 0;
                    }
                }
            }
        }

        
        board = nextBoard;
    }
};
