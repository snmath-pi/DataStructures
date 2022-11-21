#include<iostream>
#include<queue>
using namespace std; 
struct Node{
    int data ;
    Node* left ;
    Node* right ;
    CreateNode(int x) ;
};
Node*CreateNode(int x){
    Node* new_node = new Node() ;
    new_node->data = x ;
    new_node->left = new_node->right = NULL ;
    return new_node ;


}
bool isStructSame(struct Node* node1 , struct Node* node2){
    if(!node1 && !node2){
        return true; 
    }
    if(node1 && node2 && 
        isStructSame(node1->left , node2->left) &&
        isStructSame(node1->right , node2->right)){
        return true; 
    }
    return false ;
}
void mirror(struct Node* node){
    if(!node) return ;
    Node* temp ;
    mirror(node->left) ;
    mirror(node->right) ;
    temp = node->left ;
    node->left = node->right ;
    node->right = temp ;
}
bool isFoldable(struct Node* node){
    if(!node) return 1 ;
    bool res  ;

    mirror(node->left) ;
    res = isStructSame(node->left , node->right) ;
    mirror(node->left) ;
    return res; 
}
int main(){
    struct Node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->right = CreateNode(4);
    root->right->left = CreateNode(5);
    isFoldable(root)?  cout << "Yes" : cout << "No";
    return 0;
}
