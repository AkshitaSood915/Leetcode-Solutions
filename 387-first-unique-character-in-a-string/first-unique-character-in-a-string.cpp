class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        queue<int>q;

        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end()){
                q.push(i);
            }
            mpp[s[i]]++;

            while(q.size()>0 && mpp[s[q.front()]]>1){
                q.pop();
            }
        }
          return q.empty()?-1:q.front();
    }
};