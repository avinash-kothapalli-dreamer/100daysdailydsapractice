//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>>graph(N+1);
	    
	    vector<int>indegree(N+1,0);
	    
	    for(int i=0;i<P;i++){
	        int u = prerequisites[i][1];
	        int v = prerequisites[i][0];
	        
	        indegree[v]++;
	        
	        graph[u].push_back(v);
	    }
	    
	    queue<int>q;
	    vector<int>ans;
	    
	    for(int i=0;i<N;i++) if(indegree[i]==0) q.push(i);
	    
	    int cnt = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        cnt++;
	        q.pop();
	        
	        for(auto it:graph[node]){
	            indegree[it]--;
	            
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    
	    if(ans.size()==N) return ans;
	    
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends