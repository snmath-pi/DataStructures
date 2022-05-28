#include<bits/stdc++.h>
using namespace std ;
int gcd(int a , int b) {
	 return (b==0) ?a:gcd(b , a%b) ;
}
void leftRotate(int *a , int d , int n) {
	d = d % n ;
	int g = gcd(d , n) ;
	for(int i=0 ; i< g ;++i){
		int temp = a[i] ;
		int j = i ;
		while(1){
			int k = j + d ;
			if(k >= n) k-= n ;
		   	if(k == i) break ;
			a[j] = a[k] ;
			j = k ;	
		}
		a[j] = temp ;	
	}
}
void print(int *a , int n){
	for(int i=0;i<n;++i) cout << a[i] << " " ;
}
int main(){
	int a[] = {1 , 2 , 3 , 4 ,5 , 6 , 7} ;
	int n = sizeof(a)/sizeof(a[0]) ;
	leftRotate(a , 2 , n ) ;
	print(a , n) ;

}
