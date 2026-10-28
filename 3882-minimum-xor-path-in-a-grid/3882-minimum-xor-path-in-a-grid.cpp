class Solution {
public:
    int m, n;
    int ans = INT_MAX;

    vector<vector<vector<bool>>> vis;

    void dfs(vector<vector<int>>& grid, int i, int j, int xr) {
        xr ^= grid[i][j];

        if (vis[i][j][xr])
            return;

        vis[i][j][xr] = true;

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        if (i + 1 < m)
            dfs(grid, i + 1, j, xr);

        if (j + 1 < n)
            dfs(grid, i, j + 1, xr);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<vector<bool>>(
            n, vector<bool>(1024, false)
        ));

        dfs(grid, 0, 0, 0);

        return ans;
    }
};