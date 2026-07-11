class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int node, int &nodes, int &edges) {
        vis[node] = true;
        nodes++;
        edges += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeCount = 0;

                dfs(i, nodes, edgeCount);

                edgeCount /= 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};