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
Node* LevelOrder(struct Node* node , int data){
    if(!node){
        node->data = data ;
        return node ;
    }
    queue<Node*> q ;
    q.push(node) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(temp->left != NULL){
            q.push(temp->left); 
        }
        else{
            temp->left = CreateNode(data) ;
            return node;
        }
        if(temp->right != NULL){
            q.push(temp->right) ;

        }else{
            temp->right = CreateNode(data) ;
            return node ;
        }
    }
    return node ;
}
void Inorder(struct Node* node){
    if(!node){
        return ;
    }
    Inorder(node->left) ;
    cout << node->data << " " ;
    Inorder(node->right) ;

}
bool treeContinuous(struct Node* ptr){
    if(ptr == NULL)
        return true ;
    if(ptr->left == NULL  && ptr->right == NULL)
        return true ;
    if(ptr->left == NULL){
        return (abs(ptr->data - ptr->right->data) == 1) && treeContinuous(ptr->right) ;
    }
    if(ptr->right == NULL ){
        return (abs(ptr->data - ptr->left->data) == 1) && treeContinuous(ptr->left) ;
    }
    return  abs(ptr->data-ptr->left->data) ==1  && 
            abs(ptr->data - ptr->right->data) == 1 && 
            treeContinuous(ptr->left) && treeContinuous(ptr->right) ;
}
int main(){
    struct Node *root = CreateNode(3);
    root->left        = CreateNode(2);
    root->right       = CreateNode(4);
    root->left->left  = CreateNode(10);
    root->left->right = CreateNode(3);
    root->right->right = CreateNode(5);
    treeContinuous(root)?  cout << "Yes" : cout << "No";
    return 0;
}
