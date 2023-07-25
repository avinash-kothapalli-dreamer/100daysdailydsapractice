class Solution {
public:
    int findIntegers(int n) {
        int arr[32] ;
        arr[0] = 1;
        arr[1] = 2;
        
        for(int i = 2;i<32;i++) arr[i] = arr[i-1]+arr[i-2];
        
        int i = 30,prev_bit=0,ans=0;
        
        while(i>=0){
           if(n & (1 << i)){
               ans+=arr[i];
               if(prev_bit == 1){
                   ans--;
                   break;
               }
               
               prev_bit = 1;
           }else{
               prev_bit = 0;
           } 
            i--;
        }
        
       return ans+1; 
        
    }
};