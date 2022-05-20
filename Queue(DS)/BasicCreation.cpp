#include<bits/stdc++.h>
using namespace std ;
class Queue{
	public:
	int front , rear , size ;
	unsigned capacity ;
	int * ar ;
} ;

Queue* CreateQueue(unsigned capacity){
	Queue* queue = new Queue() ;
	queue->capacity = capacity ;
	queue->front = queue->size = 0 ;

	queue->rear = capacity - 1 ;
	queue->ar = new int[queue->capacity] ;

	return  queue ;

}
int is_Full(Queue *queue){
	return (queue->size == queue->capacity );
}
int is_Empty(Queue *queue){
	return (queue->size == 0 ) ;

}

void enqueue(Queue* queue , int item ){
	if(is_Full(queue)) 
		return  ;
	queue->rear = (queue->rear + 1) % queue->capacity ;
	queue->ar[queue->rear] = item ;
	queue->size = queue->size + 1 ;
	cout << item << "enqueued to queue\n"; 

}
int dequeue(Queue* queue ){
	if(is_Empty(queue))
		return INT_MIN ;
	int item = queue->ar[queue->front] ;
	queue->front = (queue->front + 1) % queue->capacity ;
	queue->size = queue->size - 1 ;
	return  item ;

}
int front(Queue* queue){
	if(is_Empty){
		return INT_MIN ;
	}
	return queue->ar[queue->front] ;
}
int rear(Queue* queue){
	if(is_Full)
		return INT_MAX ;
	return queue->ar[queue->rear] ;
}




int main(){
	Queue * queue = CreateQueue(1000) ;
	enqueue(queue , 10) ;
	enqueue(queue , 20) ;
	enqueue(queue , 30) ;
	enqueue(queue , 40) ;
	
	cout << dequeue(queue ) <<"dequeued from the queue\n" ;
	cout << "The front item is " << front(queue) << "\n" ;
	cout << "The rear item is " << rear(queue) << "\n" ;
}
