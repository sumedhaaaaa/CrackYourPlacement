class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == '$')
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int temp = mat[i][j];
        mat[i][j] = '$';

        int ways = solve(m, n, i + 1, j, dp, mat) + solve(m, n, i, j + 1, dp, mat);
        dp[i][j] = ways;

        mat[i][j] = temp;

        return ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> mat(m, vector<int>(n, 0)); // Initialize with zeros
        return solve(m, n, 0, 0, dp, mat);
    }
};
