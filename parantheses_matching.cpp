#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char data;
	struct Node* next;
} *top = NULL;

void push(char x) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	if (t == NULL) {
		printf("Stack overflow");
	}
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

char pop() {
	char x = ' ';
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	if (top == NULL) {
		printf("Stack is empty");
	}
	else {
		t = top;
		t->data = x;
		top = top->next;
		free(t);
	}
	return x;
}

void Display() {
	struct Node* t = top;
	while (t) {
		printf("%d ", t->data);
		t = t->next;
	}
}

int isBalanced(char* c) {
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == '(' || c[i] == '[' || c[i] == '{') 
			push(c[i]);
		else if (c[i] == ')' || c[i] == ']' || c[i] == '}') {
			if (top == NULL) return 0;
			pop();
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

int main(){
	char exp[203] = "( a + 1 ) + 2 (";
	printf("%d ", isBalanced(exp));
	return 0;
}


