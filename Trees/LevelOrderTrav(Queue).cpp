#include<iostream>
#include<utility>
#include<queue>

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
void LevelOrderTraversal(N*root){
    if(root == NULL) return    ;
    queue<N*> q ;
    q.push(root) ;
    while(!q.empty()){
        N* node = q.front() ;
        // q.pop() ;
        cout << node-> val << " " ;
        q.pop() ;

        if(node->left) q.push(node->left) ;
        if(node->right) q.push(node->right) ;
    }


}
int main(){
    N* root = new N(1) ;
    root->left = new N(2) ;
    root->right = new N(3) ;

    root->left->left = new N(3) ;
    root->left->right = new N(4) ;
    // root->right->right = new N(5) ;
    LevelOrderTraversal(root) ;
    

}
