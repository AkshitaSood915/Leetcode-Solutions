class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();

        if(m!=n)
        return false;

        if((s+s).find(goal)!=string::npos){
        return true;
        }
        return false;
    }  
};