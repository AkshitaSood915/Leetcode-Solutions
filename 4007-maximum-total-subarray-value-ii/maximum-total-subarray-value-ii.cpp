class Solution {
public:
    using ll = long long;

    pair<ll, ll> getLess(vector<int>& nums, ll limit) {
        int n = nums.size(), left = 0;
        deque<int> maxD, minD;
        deque<pair<ll, ll>> maxQ, minQ;

        ll count = 0, sum = 0;
        ll sumMax = 0, sumMin = 0;

        for (int right = 0; right < n; right++) {
            ll x = nums[right];

            while (!maxD.empty() && nums[maxD.back()] <= x) maxD.pop_back();
            maxD.push_back(right);

            while (!minD.empty() && nums[minD.back()] >= x) minD.pop_back();
            minD.push_back(right);

            ll cnt = 1;
            while (!maxQ.empty() && maxQ.back().first <= x) {
                sumMax -= maxQ.back().first * maxQ.back().second;
                cnt += maxQ.back().second;
                maxQ.pop_back();
            }
            maxQ.push_back({x, cnt});
            sumMax += x * cnt;

            cnt = 1;
            while (!minQ.empty() && minQ.back().first >= x) {
                sumMin -= minQ.back().first * minQ.back().second;
                cnt += minQ.back().second;
                minQ.pop_back();
            }
            minQ.push_back({x, cnt});
            sumMin += x * cnt;

            while (!maxD.empty() && !minD.empty() &&
                   nums[maxD.front()] - nums[minD.front()] >= limit) {

                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();

                sumMax -= maxQ.front().first;
                maxQ.front().second--;
                if (maxQ.front().second == 0) maxQ.pop_front();

                sumMin -= minQ.front().first;
                minQ.front().second--;
                if (minQ.front().second == 0) minQ.pop_front();

                left++;
            }

            count += right - left + 1;
            sum += sumMax - sumMin;
        }

        return {count, sum};
    }

    ll totalRangeSum(vector<int>& nums) {
        int n = nums.size();
        ll totalMax = 0, totalMin = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                totalMax += 1LL * nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                totalMin += 1LL * nums[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }

        return totalMax - totalMin;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        ll totalSubarrays = 1LL * n * (n + 1) / 2;
        ll totalSum = totalRangeSum(nums);

        ll low = 0;
        ll high = *max_element(nums.begin(), nums.end()) -
                  *min_element(nums.begin(), nums.end());

        while (low < high) {
            ll mid = (low + high + 1) / 2;

            auto lessData = getLess(nums, mid);
            ll countGreaterEqual = totalSubarrays - lessData.first;

            if (countGreaterEqual >= k) low = mid;
            else high = mid - 1;
        }

        ll threshold = low;

        auto lessData = getLess(nums, threshold);
        ll countGreaterEqual = totalSubarrays - lessData.first;
        ll sumGreaterEqual = totalSum - lessData.second;

        return sumGreaterEqual - (countGreaterEqual - k) * threshold;
    }
};