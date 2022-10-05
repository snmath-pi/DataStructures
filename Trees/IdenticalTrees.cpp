#include<iostream>
using namespace std ;
class N{
public:
    int val ;
    N* left ;
    N* right ;
    N(int x){
        this->val = x ;
        left = right = NULL ;

    }
};
bool CheckIfSame(N*p , N* q){
    if(!p || !q) return (p==q) ;
    return (p->val == q->val) && CheckIfSame(p->left , q->left) && CheckIfSame(p->right , q->right) ;
}
int main(){
    N* root = new N(1) ;
    root->left = new N(2) ;
    root->left->left = new N(3) ;
    root->left->right = new N(4) ;
    root->right = new N(5) ;
    N* r2 = new N(1) ;
    r2->left = new N(2) ;
    r2->left->left = new N(3) ;
    r2->left->right = new N(4) ;
    r2->right = new N(5) ;
    cout << CheckIfSame(root , r2) ;

}
