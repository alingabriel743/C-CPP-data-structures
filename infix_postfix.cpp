#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char data;
	struct Node* next;
}*top = NULL;

void push(char x) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	if (t->next == NULL) printf("Stack overflow");
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}

char pop() {
	char x = ' ';
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	if (t->next == NULL) printf("Stack is empty");
	else {
		t = top;
		x = t->data;
		top = t->next;
		free(t);
	}

	return x;
}

void display(){
	struct Node* p;
	p = top;
	while (p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int isOperand(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') return 0;
	else return 1;
}

int pre(char x) {
	if (x == '+' || x == '-') return 1;
	else if (x == '*' || x == '/') return 2;
	return 0;
}

char* postfix(char* infix) {
	char *post = (char*)malloc(strlen(infix)*sizeof(char) + 1);
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		if (isOperand(infix[i])) {
			post[j++] = infix[i++];
		}
		else {
			if (pre(infix[i]) > pre(top->data))
				push(infix[i++]);
			else post[j++] = pop();
		}
	}
	while (top != NULL) {
		post[j++] = pop();
	}
	post[i++] = '\0';
	return post;
}

int main() {
	
	char infix[30] = "a+b*c-d/e";
	push('#');
	char* post = postfix(infix);
	printf("%s ", post);

	return 0;
	
}