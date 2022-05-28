#include<bits/stdc++.h>
using namespace std ;
int gcd(int a , int b) {
	 return (b==0) ?a:gcd(b , a%b) ;
}
void print(int *a , int n ){
	for(int i =0;i<n;++i) cout << a[i] << " " ;
}
void Reverse(int *a , int l , int r) {
	while(l<r){
		int temp  = a[l] ;
		a[l] = a[r] ;
		a[r] = temp ;
		l++ ;
		r-- ;
	}

}
void Rotate(int *a , int d , int n){
	Reverse(a , 0 , d-1 ) ;
	Reverse(a , d , n-1 ) ;
	Reverse(a , 0 , n-1 ) ;
}
int main(){
	int a[] = {1 , 2 , 3 , 4 ,5 , 6 , 7} ;
	int n = sizeof(a)/sizeof(a[0]) ;
	Rotate(a , 2 , n) ;
	print(a , n) ;

}
