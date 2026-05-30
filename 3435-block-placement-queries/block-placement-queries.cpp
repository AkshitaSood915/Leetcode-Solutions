class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = 0;
        for (auto &q : queries) N = max(N, q[1]);
        
        vector<int> seg(4 * (N + 2), 0);
        
        auto update = [&](auto &&self, int idx, int val, int node, int l, int r) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) self(self, idx, val, 2 * node, l, mid);
            else self(self, idx, val, 2 * node + 1, mid + 1, r);
            seg[node] = max(seg[2 * node], seg[2 * node + 1]);
        };
        
        auto query = [&](auto &&self, int ql, int qr, int node, int l, int r) -> int {
            if (qr < l || r < ql) return 0;
            if (ql <= l && r <= qr) return seg[node];
            int mid = (l + r) / 2;
            return max(self(self, ql, qr, 2 * node, l, mid),
                       self(self, ql, qr, 2 * node + 1, mid + 1, r));
        };
        
        set<int> obs;
        obs.insert(0);
        vector<bool> ans;
        
        for (auto &q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obs.upper_bound(x);
                int l = *prev(it);
                
                if (it != obs.end()) {
                    int r = *it;
                    update(update, r, r - x, 1, 0, N);
                }
                
                obs.insert(x);
                update(update, x, x - l, 1, 0, N);
            } else {
                int x = q[1], sz = q[2];
                int prevObs = *prev(obs.upper_bound(x));
                int best = max(query(query, 0, x, 1, 0, N), x - prevObs);
                ans.push_back(best >= sz);
            }
        }
        
        return ans;
    }
};