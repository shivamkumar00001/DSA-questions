class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    void dfs(vector<vector<int>>& heights, int i, int j, vector<int>& a) {
        // boundary → Pacific
        if (i < 0 || j < 0) {
            a[0] = 0;
            return;
        }
        // boundary → Atlantic
        if (i >= n || j >= m) {
            a[1] = 1;
            return;
        }

        if (vis[i][j]) return;
        vis[i][j] = 1;

        if (i == 0 || heights[i][j] >= heights[i - 1][j])
            dfs(heights, i - 1, j, a);

        if (j == 0 || heights[i][j] >= heights[i][j - 1])
            dfs(heights, i, j - 1, a);

        if (i == n - 1 || heights[i][j] >= heights[i + 1][j])
            dfs(heights, i + 1, j, a);

        if (j == m - 1 || heights[i][j] >= heights[i][j + 1])
            dfs(heights, i, j + 1, a);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis.assign(n, vector<int>(m, 0));
                vector<int> a = {-1, -1};

                dfs(heights, i, j, a);

                if (a[0] == 0 && a[1] == 1) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
