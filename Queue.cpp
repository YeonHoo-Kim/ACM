#include<cstdio>
#include<stdlib.h>

typedef struct Node_ {

	int data;
	struct Node_* link;

}Node;

typedef struct Queue {

	Node* front;
	Node* rear;
	int count;

}Queue;

void init(Queue* q);
bool IsEmpty(Queue* q);
void Enqueue(Queue* q, int data);
int Dequeue(Queue* q);

int main() {

	Queue q;

	init(&q);
	for (int i = 1; i <= 10; i++)
		Enqueue(&q, i);

	while (!IsEmpty(&q))
		printf("%d ",Dequeue(&q));

	printf("%d\n");
	return 0;
}

void init(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}

bool IsEmpty(Queue* q) {
	if (q->count == 0)
		return true;
	else
		return false;
}

void Enqueue(Queue* q, int data) {
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;

	if (IsEmpty(q))
		q->front = temp;
	else
		q->rear->link = temp;
	q->rear = temp;
	q->count++;
}

int Dequeue(Queue* q) {
	
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));

	int data;
	if (IsEmpty(q))
		return 0;
	temp = q->front;
	data = temp->data;
	q->front = temp->link;
	free(temp);
	q->count--;
	return data;
}