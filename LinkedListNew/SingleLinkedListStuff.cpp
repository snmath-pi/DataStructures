#include<iostream>
#include<vector>
using namespace std;


struct Node {
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = nullptr;
	}
};

Node* fun(vector<int> op) {
	Node* head = new Node(op[0]);
	Node* temp = head;
	for(int i=1; i<op.size(); i++) {
		Node* p = new Node(op[i]);
		temp->next = p;
		temp = p;
	}
	return head;
}

void printll(Node* head) {
	for(;head; head=head->next) {
		cout << head->data << ' ';
	}
	cout << '\n';
}
Node* deletehead(Node* head) {
	if(head==nullptr) return head;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}
void deleteTail(Node* head) {
	if(head == nullptr or head->next == nullptr) return;
	for(; head->next->next!=nullptr; head = head->next){}
	Node* temp = head->next;
	head->next = nullptr;
	delete temp;
}

Node* deleteKth(Node* head, int k) {
	if(head==nullptr) return head;
	if(k==1) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	Node* temp = head; 
	int cnt = 1;
	Node* prev = temp;
	for(; temp; prev = temp, temp = temp->next, cnt++) {
		if(cnt == k) {
			prev->next = temp->next;
			delete temp;
			return head;
		}
	}
	delete temp;
	return head;
}
Node* deletevalue(Node* head, int val) {
	Node* temp = head; Node* prev;
	for(; temp; prev = temp, temp = temp->next) {
		if(temp->data==val) {
			prev->next = temp->next;
			delete temp;
			return head;
		}
	}
	delete temp;
	return head;
}

Node *inserthead(Node* head, int val) {
	Node* temp = new Node(val);
	temp->next = head;
	return temp;
}
Node* insertatend(Node* head, int val) {
	Node *temp = head;
	for(; temp->next; temp = temp->next);
	Node* n = new Node(val);
	temp->next = n;
	n->next = nullptr;
	return head;
}

Node* insertatKth(Node* head, int k, int val) {
	if(head == nullptr) {
		if(k==1) {
			return new Node(val);
		}
		else return nullptr;
	}
	if(k==1) {
		Node* temp = new Node(val);
		temp->next = head;
		return temp;
	}
	Node *temp = head;
	int cnt = 2;
	for(; temp; temp = temp->next, cnt++) {
		if(cnt==k) {
			Node* n = new Node(val);
			n->next = temp->next;
			temp->next = n;
			return head;
		}
	}	
	return head;
}
Node* insertbeforeval(Node* head, int val, int val2) {
	if(head==nullptr) return head;
	Node* temp = head;
	for(; temp->next; temp = temp->next) {
		if(temp->next->data==val) {
			Node* n = new Node(val2);
			n->next = temp->next;
			temp->next = n;
			return head;
		}
	}
	return head;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> a = {1, 2, 3, 4, 5};
	// converting a vector to a linked list
	Node* head = fun(a);
	// printing the linked list
	printll(head);
	// deleting head
	head = deletehead(head);
	printll(head);
	// deleting tail of the ll
	deleteTail(head);
	printll(head);
	// deleting the kth element of ll
	deleteKth(head, 2);
	printll(head);
	// deleting a value
	deletevalue(head, 4);
	printll(head);
	// inserting at the head;
	head = inserthead(head, 1);
	printll(head);
	// insert at the end
	insertatend(head, 10);
	printll(head);
	// insert at kth position
	insertatKth(head, 2, 20);
	printll(head);
	// insert beffore a value 
	insertbeforeval(head, 20, 69);
	printll(head);
		
}
