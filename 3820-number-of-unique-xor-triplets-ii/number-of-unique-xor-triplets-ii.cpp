class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;
        vector<vector<char>> dp(4, vector<char>(M, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            for (int k = 2; k >= 0; k--) {
                for (int v = 0; v < M; v++) {
                    if (dp[k][v])
                        dp[k + 1][v ^ x] = 1;
                }
            }
        }

        vector<char> vis(M, 0);

        for (int x : nums) vis[x] = 1;          // x^x^x and x^x^y
        for (int v = 0; v < M; v++)
            if (dp[3][v]) vis[v] = 1;           // three distinct indices

        int ans = 0;
        for (int x : vis) ans += x;
        return ans;
    }
};