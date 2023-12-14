#include<bits/stdc++.h>
using namespace std;

class Node 
{
	public:
	int data;
	Node* next;

	Node(int d, Node* x) {
		data = d;
		next = x;
	}
};

int main() {
	vector<int> a = {0, 1, 2, 3};
	Node* y = new Node(a[0], nullptr);

	cout << y->data;
}
