//#include<bits/stdc++.h>
#include <algorithm>
#include <list> 
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std ;
#define ll long long 
#define all(x) (x).begin() , (x).end()
#define sz(x) (x).size() 
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,b,a) for(int i=a-1;i>=b;--i)
#define vi vector<int> 
#define vl vector<long long>
#define vs vector<string>
#define vc vector<char> 
#define pi pair<int,int> 
#define pll pair<ll,ll> 
#define pc pair<char,char> 
#define pic pair<int,char> 
#define f first 
#define s second 
#define str string
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define fast_io std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr) ;
/******************************************************************************/
ll MOD = 1e9 + 7 ;
// ll MOD = 998244353 ; 
ll binpow(ll a, ll b) {a %= MOD;ll res = 1;while (b 
> 0) {if (b & 1){res = res * a % MOD;}a = a * a % MOD;b >>= 1;}return res;}

ll int_sqrt (ll x) {ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}

bool isPrime(ll n){if(n == 1) return false ;for(ll i=2; i*i<=n; i++){if(n%i==0)return false ;}return true;}

int cuberoot(int n){double a  = floor(pow(n , 1/3.0) + 1e-6); double dx  = (n - a* a * a) / 3.0 / a / a ;return (a + dx) ;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*********************************	*********************************************/
/* check for LONG LONG!!! !! */
struct Graph{
	int V ;
	list<int>* adj ;
	// vector<int> *adj ;

	void dfsutil(int v , vector<bool>& vis) ;
	Graph(int V) ;
	void addEdge(int u , int v) ;
	int findMother() ;


};
Graph::Graph(int V){
	this->V = V ;
	adj = new list<int> [V] ;


}
void Graph::dfsutil(int v , vector<bool>&vis){
	vis[v] = true ;
	for(auto x:adj[v]){
		if(!vis[x]){
			dfsutil(x , vis) ;
		}
	}
}
void Graph::addEdge(int u , int v){
	adj[u].pb(v) ;
}
int Graph::findMother(){
	vector<bool> vis(V , false) ;
	int v = 0 ;
	FOR(i,0,V){
		if(!vis[i]){
			dfsutil(i , vis); 
			v = i ;
		}
	}
	fill(all(vis) , false) ;
	dfsutil(v , vis); 
	FOR(i,0,V){
		if(!vis[i])
			return -1 ;
	}
	return v ;

}

void math_pi() {
	Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);


    cout << "MOther Vertex is : : : " <<  g.findMother() << "\n" ;
    
   


}

int main() {
    fast_io

    int t = 1 ;
    // std::cin >> t;
    while(t--) {
        math_pi() ;
    }
}









