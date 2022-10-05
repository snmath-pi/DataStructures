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
int height(N* root ,int &diameter){
    if(root == NULL) return 0 ;
    
    int lh = height(root->left , diameter) ;
    int rh = height(root->right , diameter) ;
    diameter = max(diameter , lh + rh) ;
    return 1 + max(lh , rh) ;
}
int Diameter(N*root){
    int diameter = 0 ;
    height(root , diameter) ;
    return diameter ;
}
int main(){
    N* root = new N(1) ;
    root->left = new N(2) ;
    root->left->left = new N(3) ;
    root->left->right = new N(4) ;
    root->right = new N(5) ;
    cout << Diameter(root) ;

}
