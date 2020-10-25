#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct Stack {
	int size;
	int top;
	int* s;
};

int isEmpty(struct Stack st) {
	return st.top == -1;
}

int isFull(struct Stack st) {
	return st.top == st.size - 1;
}

int stackTop(struct Stack st) {
	if (!isEmpty(st)) return st.s[st.top];
	return -1;
}

void Create(struct Stack* st) {
	printf("Enter the size of the stack: "); scanf("%d", &st->size);
	st->top = -1;
	st->s = (int*)malloc(st->size * sizeof(int));
}

void push(struct Stack* st, int element) {
	if (st->top == st->size - 1) 
		printf("Stack Overflow");
	else {
		st->top++;
		st->s[st->top] = element;
	}
}

int pop(struct Stack* st) {
	int x = -1;
	if (st->top == -1)
		printf("Stack Underflow");
	else {
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

void display(struct Stack st) {
	for (int i = st.top; i >= 0; i--) {
		printf("%d ", st.s[i]);
	}
	printf("\n");
}

int peek(struct Stack st, int pos) {
	int x = -1;
	if (st.top - pos + 1 < 0)
		printf("Invalid position");
	else 
		x = st.s[st.top - pos + 1];
	return x;
}


int main() {
	struct Stack st;
	Create(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);

	printf("%d \n", peek(st, 2));
	display(st);
	return 0;
}