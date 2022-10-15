class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleDetect(int i , int V , vector<int>&vis , vector<int> adj[]){
        vis[i] = 1; 
        queue<pair<int,int>> q ;
        q.push({i,-1}) ;
        while(!q.empty()){
            int node = q.front().first ;
            int par = q.front().second ;
            q.pop() ;
            for(auto x: adj[node]){
                if(!vis[x]){
                    vis[x] = 1 ;
                    q.push({x,node}) ;
                }
                else if(par != x){
                    return true ;
                }
            }
        }
        return false ;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0) ;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleDetect(i , V , vis ,adj)){
                    return true ;
                } ;
            }
        }
        return false ;
    }
};
