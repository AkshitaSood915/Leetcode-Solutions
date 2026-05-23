class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
       int  five=0,ten=0;
       int n=arr.size();

       for(int i=0;i<n;i++){
        if(arr[i]==5)
        five=five+1;

        else if(arr[i]==10){

            if(five){
            five=five-1;
            ten=ten+1;
       }
            else {
            return false;
        }
}    

      else{
            if(ten && five){
                ten=ten-1;
                five=five-1;
            }
                else if(five>=3)
                    five=five-3;
                
               else return false;
            }
        }
                return true;
    }
};