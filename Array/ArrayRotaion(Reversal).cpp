//O(n)
#include<bits/stdc++.h>
using namespace std; 
void reverseii(int ar[] , int s  , int e ){
    while(s<e){
        int t = ar[s] ; 
        ar[s] = ar[e] ;
        ar[e] = t ;
        s++ ;
        e-- ;

    }
}
void reversearray(int ar[] , int d , int n ){
    if(!d) 
        return  ;
    d%=n  ;
    reverseii(ar,0,d-1) ;
    reverseii(ar,d,n-1) ;
    reverseii(ar,0,n-1) ;

}
void printarray(int ar[] , int n ){
    for(int i=0;i<n;++i)
        cout<<ar[i] << ' '; 
}
int main(){
    int ar[] = {1,2,3,4,5,5,7}; 
    int n = sizeof(ar) / sizeof(ar[0] ) ; 
    reversearray(ar,2,n) ;
    printarray(ar,n) ; 
}
