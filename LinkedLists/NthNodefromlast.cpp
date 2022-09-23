#include<bits/stdc++.h>
using namespace std ;
struct Node{
	int data ;
	struct Node* next ;
};
int NthformLast(struct Node* head , int N){
	struct Node* temp = head; 
	int len = 0 ;
	while(temp ){
		temp = temp->next ;
		len++ ;
	}
	if(len < N){
		return 0 ;
	}
	temp = head ;
	for(int i = 1; i<len - N  +1 ; i++){
		temp = temp->next ;
	}
	return temp->data ;
}
void push(struct Node*&head , int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)) ;
	temp ->data = data ;
	temp->next = head ;
	head = temp ;

}
void printelements(struct Node* head ){
	struct Node* temp = head ;
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
	// printelements(head) ;
	cout << NthformLast(head , 4 ) ;


	
}
