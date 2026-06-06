class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0, left = 0;
        for (int x : nums) total += x;

        vector<int> ans;
        for (int x : nums) {
            int right = total - left - x;
            ans.push_back(abs(left - right));
            left += x;
        }

        return ans;
    }
};