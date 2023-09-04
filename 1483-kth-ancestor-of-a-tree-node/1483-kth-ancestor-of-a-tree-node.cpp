class TreeAncestor {
public:
    vector<vector<int>>v;
    TreeAncestor(int n, vector<int>& parent) {
      vector<vector<int>>graph(n,vector<int>(20));
      
        for(int i=0;i<n;i++){
           graph[i][0] = parent[i];
        }
        
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                if (graph[j][i-1] == -1) graph[j][i] = -1;
                else
                graph[j][i] = graph[graph[j][i-1]][i-1];
            }
        }
        
        swap(v,graph);
    }
    
    int getKthAncestor(int node, int k) {
         for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */