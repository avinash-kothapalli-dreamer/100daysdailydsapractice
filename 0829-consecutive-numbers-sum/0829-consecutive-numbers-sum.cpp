class Solution {
public:
    // int f(int n){
    //     if(n <= 0) return 0;
    //     if(n==1 || n==2) return 1;
        
    // }
    int consecutiveNumbersSum(int n) {

        int cnt =0;
        for(int i=1;i<=sqrt(2*n);i++){
            int helper = i*(i-1);
            helper/=2;
            int help1 = n -helper;

            if(help1%i==0) cnt++;
        }

        return cnt;
    }
};