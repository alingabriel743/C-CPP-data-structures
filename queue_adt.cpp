#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int size;
	int front;
	int rear;
	int* qu;
};

void create(struct Queue* q, int size) {
	q->size = size;;
	q->front = q->rear = -1;
	q->qu = (int*)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue* q, int x) {
	if (q->rear == q->size - 1) printf("Queue is full");
	else {
		q->rear++;
		q->qu[q->rear] = x;
	}
}

int dequeue(struct Queue* q) {
	int x = -1;
	if (q->rear == q->front) printf("Empty");
	else {
		q->front++;
		x = q->qu[q->front];
	}
	return x;
}

void display(struct Queue q) {
	for (int i = q.front+1; i <= q.rear; i++) {
		printf("%d ", q.qu[i]);
	}
	printf("\n");
}

int main() {
	struct Queue q;
	create(&q, 5);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	display(q);
	printf("%d ", dequeue(&q));

	return 0;

}