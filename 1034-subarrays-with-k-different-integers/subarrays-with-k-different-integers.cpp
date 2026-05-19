class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Exactly k distinct = At most k - At most (k-1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;

        int count = 0;

        unordered_map<int, int> mpp;

        // Outer while loop
        while (right < nums.size()) {

            // Add current element
            mpp[nums[right]]++;

            // Shrink window if distinct elements exceed k
            while (mpp.size() > k) {

                mpp[nums[left]]--;

                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }

                left++;
            }

            // Count valid subarrays
            count += (right - left + 1);

            right++;
        }

        return count;
    }
};