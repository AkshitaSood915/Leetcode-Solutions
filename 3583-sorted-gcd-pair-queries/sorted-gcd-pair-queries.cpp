class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1, 0), exact(mx + 1, 0);

        // Count numbers divisible by i
        for (int i = 1; i <= mx; i++)
            for (int j = i; j <= mx; j += i)
                cnt[i] += freq[j];

        // Count pairs with exact gcd = i
        for (int i = mx; i >= 1; i--) {
            exact[i] = cnt[i] * (cnt[i] - 1) / 2;
            for (int j = i + i; j <= mx; j += i)
                exact[i] -= exact[j];
        }

        // Prefix of pair counts
        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};