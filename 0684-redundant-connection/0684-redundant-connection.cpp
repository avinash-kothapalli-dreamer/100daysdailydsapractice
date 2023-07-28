class DSU{
    private:
    vector<int>rank,parent;
    public:
    DSU(int n){
        rank.resize(n+1,1);
        
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    
    
    int findParent(int node){
        if(parent[node] == node) return node;
        return findParent(parent[node]);
    }
    
    void unionByRank(int a,int b){
        int alp = findParent(a);
        int blp = findParent(b);
        
        if(alp != blp){
            if(rank[alp]<rank[blp]){
                swap(alp,blp);
            }
            
            parent[blp] = alp;
            
            if(rank[alp]==rank[blp]) rank[alp]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        DSU dsu(edges.size());
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            if(dsu.findParent(u) != dsu.findParent(v)){
                dsu.unionByRank(u,v);
            }else{
                ans = it;
            }
        }
        
        return ans;
    }
};