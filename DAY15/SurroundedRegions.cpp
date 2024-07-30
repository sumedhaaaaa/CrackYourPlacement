class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') 
            return;
        
        board[i][j] = '#';  
        
        for(pair<int,int>& d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;
            dfs(board, ni, nj);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n = board.size();
        int m = board[0].size();
        
        
        for(int i = 0; i < n; ++i) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        for(int j = 0; j < m; ++j) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[n-1][j] == 'O') dfs(board, n-1, j);
        }
        
       
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if(board[i][j] == '#') 
                    board[i][j] = 'O';
            }
        }
    }
};
