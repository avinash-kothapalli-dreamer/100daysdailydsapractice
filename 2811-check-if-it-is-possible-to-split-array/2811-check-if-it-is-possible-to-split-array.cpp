class Solution {
public:
    long long dp[101][101];
    int f(int i,vector<int> &nums,int n,int sum,int m){
        
        if(i==n) return 1;
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int help=0;
        for(int j=i;j<n;j++){
            help += nums[j];
            //cout<<j-i+1<<help<<n-j<<sum-help<<endl;
            bool first = j-i+1==1 || help>=m;
            bool second = n-j==1 || sum-help>=m;
            
            int help1  = 0;
            if(first && second){
                //cout<<first<<second<<endl;
                //cout<<i<<j<<endl;
                int help2 = f(i,nums,j,help,m);
                //cout<<help2<<endl;
                
                int help3  = f(j+1,nums,n,sum-help,m);
               
                //cout<<help2<<help3<<endl;
                
                //cout<<i<<help1<<j<<endl;
                
                //cout<<help1<<endl;
                dp[i][n] = help2 && help3;
                
               if(help2 && help3) return 1;
                
                
            }
            
          
            
        }
        
        return 0;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(auto it:nums) sum+=it;
        return f(0,nums,nums.size()-1,sum,m);
    }
};