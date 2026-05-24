class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int i) {
            if (dp[i] != -1) return dp[i];

            int ans = 1;

            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i]) break;
                ans = max(ans, 1 + dfs(j));
            }

            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i]) break;
                ans = max(ans, 1 + dfs(j));
            }

            return dp[i] = ans;
        };

        int result = 1;
        for (int i = 0; i < n; i++) {
            result = max(result, dfs(i));
        }

        return result;
    }
};