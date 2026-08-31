class Solution {
public:
    int maxDepth(string s) {
        int openBrac=0;
        int result=0;

        for(char &ch:s){

            if(ch=='('){
            openBrac++;
            }
        else if(ch==')'){
            openBrac--;
        }
          result=max(result,openBrac);
        }
        return result;
    }
};