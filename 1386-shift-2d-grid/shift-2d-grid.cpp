class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int tot = m * n;
        k %= tot;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = (i * n + j + k) % tot;
                ans[idx / n][idx % n] = grid[i][j];
            }
        }

        return ans;
    }
};