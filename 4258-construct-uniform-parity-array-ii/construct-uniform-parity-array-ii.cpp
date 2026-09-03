class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        if (mn % 2 != 0)
            return true;

        for (int num : nums1) {
            if (num % 2 != 0)
                return false;
        }

        return true;
    }
};