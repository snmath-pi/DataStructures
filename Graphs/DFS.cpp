#include<bits/stdc++.h>
using namespace std ;
class Graph{
public:
	map<int , bool> visited ;
	map<int , list<int> > adj ;

	void edge(int v , int u);

	void dfs(int x) ;


};
void Graph::edge(int u , int v){
	adj[u].push_back(v) ;
}
void Graph::dfs(int x){
	visited[x] = 1 ;
	cout << x << " " ;

	for(auto i:adj[x] ){
		if(!visited[i]){
			dfs(i) ;
		}
	}
}
int main(){
	Graph g ;
	g.edge(0, 1);
    g.edge(0, 2);
    g.edge(1, 2);
    g.edge(2, 0);
    g.edge(2, 3);
    g.edge(3, 3);
    g.dfs(2) ;
}
