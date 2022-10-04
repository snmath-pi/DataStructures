#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std ;
class N{
public:
	int v ;
	N* l;
	N* r;
	N(int val){
		this->v = val ;
		l = r =  NULL ;
	}

};
int maxDepth(N* root){
	if(root == NULL) return 0 ;
	int ll = maxDepth(root->l) ;
	int rr = maxDepth(root->r) ;
	return 1 + max(ll , rr) ;
}
int main(){
	N* n = new N(1) ;
	

}
