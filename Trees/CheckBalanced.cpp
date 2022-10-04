#include<iostream>
using namespace std ;
class N{
public:
	int v ;
	N* l ;
	N* r ;
	N(int va){
		this->v = va ;
		l = r = NULL ;
	}

};
int height(N* root){
	if(root == NULL ) return 0 ;
	int lh = height(root->l) ;
	if(lh == -1 ) return -1 ;
	int rh = height(root->r) ;
	if(rh == -1 ) return -1 ;
	if(abs(lh - rh) > 1) return -1 ;
	return 1 ;
}
bool isBalanced(N* root){
	return height(root) != -1 ;
}
int main(){
	N* root = new N(1) ;
	root->l = new N(2) ;
	root->r = new N(3) ;
	root->l->r = new N(5) ;
	root->l->l = new N(4) ;
	cout << isBalanced(root) ;

}
