/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	if(head == nullptr) return head;

	if(pos == 0) {
		Node* temp = head;
		head = head->next;
		delete(temp);
		return head;
	}

	int cnt = 0;
	Node* temp = head; Node* prev = head;
	for(; temp != nullptr; prev = temp, temp = temp->next) {
		if(cnt == pos) {
			prev->next = prev->next->next;
			free(temp);
			break;
		}
		cnt++;
		
	}
	return head;
}
