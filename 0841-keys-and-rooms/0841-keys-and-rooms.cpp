class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            for(auto it:rooms[t]){
               if(!visited[it]) q.push(it); visited[it] = 1;
             }
            
            
        }
        
        
       for(int i=0;i<n;i++) if(!visited[i])  return false;
        
        return true;
        
    }
};