#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* back;
	Node(int val) {
		data =val;
		Node* next = nullptr;
		Node* back = nullptr;
	}
	Node(int val, Node* n, Node* b) {
		data = val;
		next = n;
		back = b;
	}
};
Node* fun(vector<int> a) {
	Node* head = new Node(a[0]);
	Node* prev = head;
	for(int i=1; i<(int) a.size(); i++) {
		Node* temp = new Node(a[i], nullptr, prev);
		prev->next = temp;
		prev = temp;
	}
	return head;
}
void printdll(Node* head) {
	for(; head; head = head->next) {
		cout << head->data << ' ';
	}
	cout << '\n';
}
Node* deletehead(Node* head) {
	if(head==nullptr) return head;
	if(head->next==nullptr) return nullptr;
	Node* temp = head;
	head = head->next;
	head->back = nullptr;
	temp->next = nullptr;
	delete temp;
	return head;
}
Node* deletetail(Node* head) {
	if(head==nullptr || head->next==nullptr) return nullptr;
	Node* temp = head;
	for(; temp->next->next; temp = temp->next){}
	Node* x = temp->next;
	temp->next = nullptr;
	x->back = nullptr;
	delete x;
	return head;

}
Node* deleteKth(Node* head, int k) {
	int cnt = 1;
	Node* temp = head;
	for(; temp && cnt != k; temp = temp->next, cnt++) {}
	Node* front = temp->next;
	Node* prev = temp->back;
	if(!front && !prev) {
		delete temp;
		return head;
	}
	if(!front) {
		prev->next = nullptr;
		temp->back = nullptr;
		delete temp;
		return head;
	}
	prev->next = front->next;
	front->back = prev;
	temp->next = nullptr; temp->back = nullptr;
	delete temp;
	return head;
}

void deletenode(Node* temp) {
	Node* prev = temp->back;
	Node* front = temp->next;
	if(!front) {
		prev->next = nullptr;
		temp->back = nullptr;
		free(temp);
		return;
	}
	prev->next = front;
	front->back = prev;
	temp->next = temp->back = nullptr;
	delete temp;
}
Node* inserthead(Node* head, int val) {
	Node* newhead = new Node(val, head, nullptr);
	head->back = newhead;
	return newhead;
}
Node* inserttail(Node* head, int val) {
	if(head->next==nullptr) {
		head =inserthead(head, val);
		return head;
	}
	Node* tail;
	for(tail = head; tail->next; tail = tail->next){}
	Node* newnode = new Node(val, tail, tail->back);
	tail->back->next = newnode;
	tail->back = newnode;
	return newnode;
}
Node* insertKth(Node* head, int val, int k) {
	if(k==1) {
		return inserthead(head, val);
	}
	Node* temp = head;
	int cnt = 1;
	for(; temp; temp=temp->next, cnt++) {
		if(cnt == k) break;
	}
	Node* prev = temp->back;
	Node* newnode = new Node(val, temp, prev);
	prev->next = newnode;
	temp->back = newnode;
	return head;
}

void insertnode(Node* node, int val) {
	Node* newnode = new Node(val, node, node->back);
	node->back->next = newnode;
	node->back = newnode;
	return;
}
void reverse(Node* head) {
	vector<int> x;
	for(;head; head=head->next) x.push_back(head->data);
	for(int i=x.size()-1; i>=0; i--) {
		cout << x[i] << ' ';
	}
	cout << '\n';
}
Node* singlepassreverse(Node* head) {
	if(head==nullptr || head->next) {
		return head;
	}
	Node* temp = head;
	Node* prev;
	for(; temp; temp = temp->back) {
		prev = temp->back;
		temp->back = temp->next;
		temp->next=  prev;
	}
	return prev->back;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> a = {1, 2, 3, 4, 5};
	// converting an array to a doubly ll
	Node* head = fun(a);
	// printing the doubly ll
	printdll(head);

	// reversing the dll using stack (two pass)
	reverse(head);

	Node* temp = singlepassreverse(head);
	printdll(temp);
}
