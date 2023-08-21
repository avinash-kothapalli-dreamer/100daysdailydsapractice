class Solution {
public:
    int findIntegers(int n) {
       int f[32]={0};
        f[0]=1;
        f[1]= 2;
        
        for(int i=2;i<32;i++) f[i] = f[i-1]+f[i-2];
        
        int i=31;
        int ans= 0;
        int prev_bit = 0;
        
        while(i>=0){
            if(n & (1<<i)){
                ans+=f[i];
                if(prev_bit==1){
                    ans--;
                    break;
                }
                prev_bit =1;
            }else{
                prev_bit=0;
            }
            
            i--;
        }
        
        return ans+1;
    }
};