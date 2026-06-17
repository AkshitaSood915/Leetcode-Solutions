class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIM = 1000000000000000LL;
        int n = s.size();

        vector<long long> len(n);
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                curr++;
            } 
            else if (ch == '*') {
                if (curr > 0) curr--;
            } 
            else if (ch == '#') {
                curr = min(LIM, curr * 2);
            } 
            else if (ch == '%') {
                // length remains same
            }

            len[i] = curr;
        }

        if (k >= curr) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long before = (i == 0 ? 0 : len[i - 1]);

            if (ch >= 'a' && ch <= 'z') {
                if (k == before) return ch;
            } 
            else if (ch == '#') {
                k %= before;
            } 
            else if (ch == '%') {
                k = before - 1 - k;
            } 
            else if (ch == '*') {
                // removed last char, existing indices unchanged
            }
        }

        return '.';
    }
};