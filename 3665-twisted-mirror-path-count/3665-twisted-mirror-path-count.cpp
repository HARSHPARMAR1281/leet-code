
class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;


    pair<int,int> move(int r, int c, int dir) {

        while (r < m && c < n && grid[r][c] == 1) {

            if (dir == 0) {
                r++;
                dir = 1;
            }
            else {
                c++;
                dir = 0;
            }
        }

        if (r >= m || c >= n)
            return {-1, -1};

        return {r, c};
    }

    int solve(int r, int c) {

        if (r == m - 1 && c == n - 1)
            return 1;

        if (dp[r][c][0] != -1)
            return dp[r][c][0];

        long long ans = 0;

        auto p1 = move(r, c + 1, 0);

        if (p1.first != -1) {
            ans += solve(p1.first, p1.second);
            ans %= MOD;
        }

        auto p2 = move(r + 1, c, 1);

        if (p2.first != -1) {
            ans += solve(p2.first, p2.second);
            ans %= MOD;
        }

        return dp[r][c][0] = ans;
    }

    int uniquePaths(vector<vector<int>>& mat) {

        grid = mat;

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1, -1)
        ));

        return solve(0, 0);
    }
};
