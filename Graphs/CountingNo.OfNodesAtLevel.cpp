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
#define ld long double
#define all(x) (x).begin() , (x).end()
#define minel *min_element(all(x)) 
#define maxel *max_element(all(x)) 
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
ll binpow(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1){res = res * a ;}a = a * a;b >>= 1;}return res;}

ll int_sqrt (ll x) {ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}

bool isPrime(ll n){if(n == 1) return false ;for(ll i=2; i*i<=n; i++){if(n%i==0)return false ;}return true;}

int cuberoot(int n){double a  = floor(pow(n , 1/3.0) + 1e-6); double dx  = (n - a* a * a) / 3.0 / a / a ;return (a + dx) ;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/******************************************************************************/
/* check for LONG LONG!!! !! */
struct Graph{
    int V ;
    Graph(int V ) ;
    list<int> *a ;
    void addEdge(int u , int v) ;
    void bfs(int s , int l) ;

};
Graph :: Graph(int V){
    this->V = V ;
    a = new list<int>[V] ;
}
void Graph::addEdge(int u , int v){
    a[u].pb(v) ;
    a[v].pb(u) ;
}
void Graph::bfs(int s , int l){
    bool *visited = new bool[V ,false] ;
    int level[V] = {0} ;
    queue<int> q ;
    q.push(s) ;
    visited[s] = true; 
    level[s] = 0;
    while(!q.empty()){
        int x = q.front() ; q.pop() ;
        for(auto y:a[x]){
            if(!visited[y]){
                visited[y] = true ;
                level[y] = level[x] + 1 ;
                q.push(y) ;
            }
        }
    }
    int cnt = 0 ;
    for(int i =0; i<V; i++){
        if(level[i] == l) cnt++ ;
    }
    cout << cnt << "\n" ;


}

void math_pi() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    int level = 2 ;
    g.bfs(0 , level) ;


    
   


}

int main() {
    fast_io

    int t = 1 ;
    // std::cin >> t;
    while(t--) {
        math_pi() ;
    }
}




// to count pairs of (i,j) that are less than some number k and are s[i]=s[j]=1
//vl pref(n+1 , 0 ) ;
// FOR(i,1,n+1){
//     pref[i] = pref[i-1] ;
//     if(s[i-1] == '1'){
//         pref[i]++ ;
//     }
//     // storing prefixes of number of ones occuring till that index
        
// }



