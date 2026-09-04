class Solution {
public:

      bool isPalindrome(string s){
        int left=0;
        int right=s.length()-1;

        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            if(isPalindrome(sub)){
               count++;
          }
         }
       }
       return count;
    }
 };