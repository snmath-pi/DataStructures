#include<bits/stdc++.h>
using namespace std ;
struct Node{
	int data ;
	struct Node* next ;
};
int NthformLast(struct Node* head , int N){
	struct Node* temp = head ;
	int len = 0 ;
	while(temp!=NULL){
		len ++ ;
		temp = temp->next ;
	}
	temp = head ;
	if(len<N)
		return 0 ;
	else{
		for(int i =1;i<len - N + 1 ; i++){
			temp = temp->next ;
		}
	}
	return temp->data ;
}
int NthNodeUsing2pointers(struct Node* head , int N){
	struct Node *main_ptr , *ref_ptr = (struct Node*)malloc(sizeof(struct Node)) ;
	main_ptr = head ; ref_ptr = head; 
	for(int i=1;i<N;i++){
		ref_ptr = ref_ptr->next ;
	}
	while(ref_ptr && ref_ptr->next){
		ref_ptr = ref_ptr->next ;
		main_ptr = main_ptr->next ;
	}
	return main_ptr->data ;

}









void push(struct Node*&head , int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)) ;
	new_node->data = data ;
	new_node->next = head ;
	head = new_node ;

}
void printelements(struct Node* head ){
	struct Node*temp = head ;
	while(temp){
		printf("%d -->" , temp->data) ;
		temp = temp->next ;
	}
}
int main() {
	struct Node* head = NULL ;
	struct Node* temp = head ;
	push(head , 1) ;
	push(head , 21) ;
	push(head , 152) ;
	push(head , 112) ;
	push(head , 14) ;
	push(head , 1123) ;
	// printelements(head) ;
	cout << NthNodeUsing2pointers(head , 1 ) ;


	
}
