class Solution {
public:
    int dp[101][26];
    int f(int i,int n,string num){
        
        if(i==num.length()) {
            if(n==0) return 0;
            else return 1e9;
        }
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int curr = num[i]-'0';
        int nonpick = 1+f(i+1,n,num);
        int pick = f(i+1,(n*10+curr)%25,num);
        
        return dp[i][n] = min(pick,nonpick);
    }
    int minimumOperations(string num) {
        
      memset(dp,-1,sizeof(dp));
        
       return f(0,0,num);
    }
};