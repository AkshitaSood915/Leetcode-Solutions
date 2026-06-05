class Solution {
public:
    long long solve(long long n) {
        if (n <= 0) return 0;

        string s = to_string(n);
        int len = s.size();

        long long dp[20][11][11][2][2];
        memset(dp, -1, sizeof(dp));

        function<long long(int,int,int,int,int)> dfs = [&](int pos, int prev2, int prev1, int tight, int started) -> long long {
            if (pos == len) return 0;

            long long &res = dp[pos][prev2][prev1][tight][started];
            if (res != -1) return res;

            res = 0;
            int limit = tight ? s[pos] - '0' : 9;

            for (int d = 0; d <= limit; d++) {
                int ntight = tight && (d == limit);

                if (!started && d == 0) {
                    res += dfs(pos + 1, 10, 10, ntight, 0);
                } else {
                    long long add = 0;

                    if (prev2 != 10) {
                        if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d))
                            add = 1;
                    }

                    long long cnt = countNums(pos + 1, ntight, s);
                    res += add * cnt + dfs(pos + 1, prev1, d, ntight, 1);
                }
            }

            return res;
        };

        return dfs(0, 10, 10, 1, 0);
    }

    long long countNums(int pos, int tight, string &s) {
        if (pos == s.size()) return 1;
        if (!tight) {
            long long ans = 1;
            for (int i = pos; i < s.size(); i++) ans *= 10;
            return ans;
        }
        long long val = 0;
        for (int i = pos; i < s.size(); i++)
            val = val * 10 + (s[i] - '0');
        return val + 1;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};