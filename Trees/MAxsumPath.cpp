#include<iostream>
using namespace std ;
class Node{
public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int val){
        this->data = val ;
        left = right = NULL ;
    }
};
int maxi(Node* root , int &x) ;
int maxPathSum(Node* root){
    int sum = -1e5 ;
    maxi(root, sum) ;
    return sum ;
}
int maxi(Node* root , int& sum){
    if(root == NULL) return 0 ;
    int lh = max(maxi((root->left) , sum) , sum) ;
    int rh = max(maxi((root->right) , sum) , sum) ;
    sum = max(sum , lh + rh + root->data) ;
    return max(lh,rh) + root->data ;

}
int main(){
    
}
