#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* lchild;
	struct Node* rchild;
} *root = NULL;

struct Node* create(struct Node*p, int key) {
	struct Node* t = NULL;
	if (!p) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data) p->lchild = create(p->lchild, key);
	else if (key > p->data) p->rchild = create(p->rchild, key);
	return p;
}

void insert(int key) {
	struct Node* t=root;
	struct Node* p;
	struct Node* r = NULL;
	if (!t) {
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}

	while (t) {
		r = t;
		if (key < t->data) t = t->lchild;
		else if (key > t->data) t = t->rchild;
		else return;
	}

	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->rchild = p->lchild = NULL;
	if (key < r->data) r->lchild = p;
	else r->rchild = p;
}

struct Node* Rsearch(struct Node* p, int key) {
	if (!p) return 0;
	if (key == p->data) return p;
	else if (key < p->data) Rsearch(p->lchild, key);
	else Rsearch(p->rchild, key);
}

struct Node* search(struct Node* p, int key) {
	while (p) {
		if (key == p->data) return p;
		else if (key < p->data) p = p->lchild;
		else p = p->rchild;
	}
	return NULL;
}

void inorder(struct Node* p) {
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

int main()
{
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);
	inorder(root);
	printf("\n");
	struct Node* t = search(root, 4);
	printf("%d ", t->data);

}