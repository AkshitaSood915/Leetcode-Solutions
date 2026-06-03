class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto solve = [&](vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2) {
            int n = s2.size();
            vector<pair<int,int>> v;
            for(int i=0;i<n;i++) v.push_back({s2[i], d2[i]});
            sort(v.begin(), v.end());

            vector<int> pref(n), suff(n);
            pref[0] = v[0].second;
            for(int i=1;i<n;i++) pref[i] = min(pref[i-1], v[i].second);

            suff[n-1] = v[n-1].first + v[n-1].second;
            for(int i=n-2;i>=0;i--) suff[i] = min(suff[i+1], v[i].first + v[i].second);

            int ans = INT_MAX;

            for(int i=0;i<s1.size();i++) {
                int finishFirst = s1[i] + d1[i];

                int idx = upper_bound(v.begin(), v.end(), make_pair(finishFirst, INT_MAX)) - v.begin();

                if(idx > 0)
                    ans = min(ans, finishFirst + pref[idx-1]);

                if(idx < n)
                    ans = min(ans, suff[idx]);
            }
            return ans;
        };

        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};