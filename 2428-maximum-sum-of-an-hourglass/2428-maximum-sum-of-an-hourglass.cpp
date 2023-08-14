class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> help(m,vector<long long>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                help[i][j] = grid[i][j];
            }
        }
        
        help[0][0] = grid[0][0];
        
        for(int i=1;i<m;i++){
            help[i][0] += help[i-1][0] ;
        }
        
        for(int j=1;j<n;j++){
            help[0][j] += help[0][j-1];
        }
        
        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                help[i][j] += help[i-1][j]+help[i][j-1]-help[i-1][j-1];
            }
        }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<help[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        long long ans = -1e9;
        
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                long long help1 = help[i+2][j+2] - grid[i+1][j+2] - grid[i+1][j] -(i>=1?help[i-1][j+2]:0) - (j>=1?help[i+2][j-1]:0)+(i>=1 && j>=1 ? help[i-1][j-1]:0);
                
                ans = max(ans,help1);
            }
        }
        
       return (int)ans;
    }
};