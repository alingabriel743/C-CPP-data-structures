#include <stdio.h>
#include <stdlib.h>
#ifndef Stack_h
#define Stack_h
struct Stack {
	int size;
	int top;
	struct Node** s;
};

void stackCreate(struct Stack *st, int size) {
	st->size = size;
	st->top = -1;
	st->s = (struct Node**)malloc(st->size * sizeof(struct Node*));
}
void push(struct Stack* st, struct Node* t) {
	if (st->top == st->size - 1) printf("Stack overflow");
	else {
		st->top++;
		st->s[st->top] = t;
	}
}

struct Node* pop(struct Stack* st) {
	struct Node* x = NULL;
	if (st->top == -1) printf("Stack is empty");
	else {
		x = st->s[st->top];
		st->top--;
	}

	return x;
}

int isEmptySt(struct Stack st) {
	if (st.top == -1) return 1;
	return 0;
}

int isFull(struct Stack st) {
	if (st.top == st.size - 1) return 1;
	else return 0;
}

#endif
