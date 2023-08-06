class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>>help(grid.size(),vector<int>(grid[0].size(),1e9));
        queue<pair<int,pair<int,int>>>q;
        vector<int>row={1,0,0,-1};
        vector<int>col = {0,1,-1,0};
        
       // vector<vector<int>>vis(grid.size(),vector<int>(grid.size(),0));
         int vis[grid.size()][grid.size()];
         memset(vis,0,sizeof(vis));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1) {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        
        
        
        while(!q.empty()){
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            help[x][y]= min(help[x][y],dist);
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow = x+row[i];
                int newcol = y+col[i];
                
                if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid.size() && vis[newrow][newcol]==0){
                    q.push({dist+1,{newrow,newcol}});
                    vis[newrow][newcol]=1;
                }
            }
            
        }
        
        for(int i=0;i<help.size();i++){
            for(int j=0;j<help.size();j++){
                cout<<help[i][j]<<" ";
            }
            cout<<endl;
        }
        int n = grid.size();
        int ans = -1e9;
        
         priority_queue<pair<int,pair<int,int>>>q1;
        
        q1.push({help[0][0],{0,0}});
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        
       while(!q1.empty()){
            int x = q1.top().second.first;
            int y = q1.top().second.second;
            
            int dist  = q1.top().first;
           
           //cout<<dist<<x<<y<<endl;
            
            q1.pop();
            
            if(x==n-1 && y == n-1) ans = max(ans,dist);
            
            for(int i=0;i<4;i++){
                int newrow = x+row[i];
                
                int newcol = y+col[i];
                
                if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid.size()&&vis[newrow][newcol]==0){
                    q1.push({min(help[newrow][newcol],dist),{newrow,newcol}});
                    vis[newrow][newcol]=1;
                }
            }
        
        
//         for(int i=0;i<help.size();i++){
//             for(int j=0;j<help.size();j++){
//                 help[i][j] = min(help[i-1][j],help[i][j-1])
//             }
//         }
           
            
        }
        
        return ans;
        
    }
};