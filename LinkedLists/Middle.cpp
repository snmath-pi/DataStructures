#include<iostream>
using namespace std ; 

class Node{
public:
	int data ;
	Node* next ;

};
class NodeOperation{
public:
	void push(class Node*&head , int new_data){
		class Node* new_node = new Node() ;

		new_node->data = new_data ;

		new_node->next = head ;

		head = new_node; 
	}
	void printNode(class Node*head){
		while(head){
			printf("%d -->" , head->data) ;
			head = head->next ;
		}
		cout << "NULL" << "\n" ;
	}
	int getLen(class Node* head){
		class Node* temp = head ;
		int len = 0 ;
		while(temp){
			len++  ;
			temp = temp->next ;
		}
		return len ;
	}
	void printMiddle(class Node*head){
		if(head){
			int len = getLen(head) ;
			class Node*temp = head ;
			int mid = len / 2 ;
			while(mid--){
				temp = temp->next ;
			}
			cout << temp->data << " ";

		}


	}

};
int main(){
	class Node* head = NULL ;
	class NodeOperation* temp = new NodeOperation() ;

	for(int i = 5 ; i >=1 ;--i ){
		temp->push(head,  i); 
		temp->printNode(head) ;
		temp->printMiddle(head); 


	}
	return 0 ;
}
