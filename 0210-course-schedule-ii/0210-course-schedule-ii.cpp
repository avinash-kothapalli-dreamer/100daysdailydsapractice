class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[v].push_back(u);
            
            indegree[u]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int help =q.front();
            ans.push_back(help);
            q.pop();
            cnt++;
            
            for(auto it:adj[help]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        
        
       if(cnt==numCourses) return ans;
        
        return {};
    }
};