class Solution {
public:
    int dp[21][21];

    int f(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        if (dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = max(
            nums[l] - f(nums, l + 1, r),
            nums[r] - f(nums, l, r - 1)
        );
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, nums.size() - 1) >= 0;
    }
};