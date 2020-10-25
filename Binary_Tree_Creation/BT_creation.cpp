#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

#pragma warning(disable:4996)

struct Node {
	int data;
	struct Node* lchild;
	struct Node* rchild;
}*root = NULL;


void create() {
	struct Node* t, * p;
	int x;
	struct Queue q;
	create(&q, 100);
	printf("Enter root value: "); scanf("%d", &x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);
	while (!isEmpty(q)) {
		p = dequeue(&q);
		printf("Enter left child of %d: ", p->data); 
		scanf("%d", &x);
		if (x != -1) {
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}
		printf("Enter right child of %d: ", p->data); scanf("%d", &x);
		if (x != -1) {
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}

void preorder(struct Node* p) {
	if (p) {
		printf("%d ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void IPreorder(struct Node* p) {
	struct Stack stk;
	stackCreate(&stk, 100);

	while (p || !isEmptySt(stk)) {
		if (p) {
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lchild;
		}
		else {
			p = pop(&stk);
			p = p->rchild;
		}
	}
}


void levelOrder(struct Node* root) {
	struct Queue qu;
	create(&qu, 100);
	enqueue(&qu, root);
	printf("%d ", root->data);
	while (!isEmpty(qu)) {
		root = dequeue(&qu);
		if (root->lchild) {
			printf("%d ", root->lchild->data);
			enqueue(&qu, root->lchild);
		}
		if (root->rchild) {
			printf("%d ", root->rchild->data);
			enqueue(&qu, root->rchild);
		}
	}

}
int main() {
	create();
	levelOrder(root);

	return 0;
}
