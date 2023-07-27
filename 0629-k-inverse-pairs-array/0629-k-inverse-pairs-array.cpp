class Solution {
public:
    int f(int n,int k,vector<vector<int>> &dp){
        if(k == 0) return 1;
        
        if(n == 0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int inv = 0;
        for(int i=0;i<=min(k,n-1);i++){
            inv = (inv + f(n-1,k-i,dp))%1000000007;
        }
        
        return dp[n][k] = inv;
    }
    int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0) dp[i][j] =1;
                else{
                    int val = (dp[i-1][j] +M - (j-i>=0 ? dp[i-1][j-i] : 0))%M;
                        dp[i][j] = (dp[i][j-1] + val)%1000000007;
                }
            }
        }
        
        return ((dp[n][k]+ M - (k>0?dp[n][k-1]:0))%M);
       
    }
};