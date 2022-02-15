//O(n)  ;
#include<bits/stdc++.h> 
using namespace std; 
void leftrotatebyone(int ar[] ,int  n){
    int i , temp = ar[0] ;
    for(int i= 0 ; i<n-1;++i)
        ar[i ] = ar[i+1 ]; 
        

    
    ar[n-1] = temp ; 
}
void leftrotate(int ar[] , int d , int n){
    for(int i = 0 ;i<d;++i){
        leftrotatebyone(ar,n) ;
    }
}
void printarray(int ar[] , int n ){
    for(int i=0;i<n;++i)
        cout<<ar[i]<<" "; 
}
int solve(){}

int main(){
    int ar[] = {100,101,102,103,104,105}  ;
    int n =sizeof(ar)/sizeof(ar[0]) ;
   
    leftrotate(ar,2,n) ;
    printarray(ar, n ) ;

    
}
