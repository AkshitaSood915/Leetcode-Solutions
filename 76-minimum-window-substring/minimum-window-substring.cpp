class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> hash(256, 0);

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int l = 0, r = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        if (startIndex == -1) return "";

        return s.substr(startIndex, minLen);
    }
};