class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);

        int left=0;
        int right=0;
        int maxLen=0;

           while(right<s.size()){
           //If present in the map
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left)
                {
                    left=hash[s[right]]+1;
                }

            }
            maxLen=max(maxLen,right-left+1);
            hash[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};