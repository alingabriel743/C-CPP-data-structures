#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
} *top = NULL;

void push(int x) {
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if (t == NULL) {
		printf("Stack is full");
	}
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop() {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	int x = -1;
	if (t == NULL) 
		printf("Stack is empty");
	else {
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void display() {
	struct Node* t = top;
	while (t) {
		printf("%d ", t->data);
		t=t->next;
	}
	printf("\n");
}

int main(){
	push(10);
	push(20);
	push(30);
	display();
	printf("%d ", pop());
	return 0;
}