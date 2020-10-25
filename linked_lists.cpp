#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct Node {
	int data;
	struct Node* next;
};


struct Node* head = NULL;

void create(int A[], int n) {
	int i;
	struct Node* t, *last;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = A[0];
	head->next = NULL;
	last = head;

	for (i = 1; i < n; i++) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void display(struct Node* p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int Rcount(struct Node* p) {
	int x = 0;
	if (!p) return x;
	else {
		x = Rcount(p->next);
		return x + 1;
	}
}

int Rsum(struct Node* p) {
	
	if (!p) return 0;
	else {
		return Rsum(p->next) + p->data;
	}
}


int Rmax(struct Node* p) {
	int max;
	if (!p) return INT32_MIN;
	max = Rmax(p->next);
	return (max > p->data) ? max : p->data;
	
}

struct Node* Rsearch(struct Node* p, int key) {
	if (!p) return NULL;
	return (key == p->data) ? p : Rsearch(p->next, key);
}

struct Node* search(struct Node* p, int key) {
	struct Node* q = NULL;
	while (p) {
		if (key == p->data) {
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
}

void Insert(int pos, int x) {
	struct Node* t, * p;
	if (pos == 0) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = head;
		head = t;
	}
	else if (pos > 0) {
		p = head;
		for (int i = 0; i < pos - 1 && p; i++)
			p = p->next;
		if (p) {
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->next = p->next;
			p->next = t;
		}
	}
}

void SortedInsert(struct Node* p, int x) {
	struct Node* t, *q = NULL;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	if (head == NULL){
		head = t;
	}
	else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == head) {
			p->next = head;
			head = p;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}


}

int Delete(int pos) {
	struct Node* p, * q;
	int x = -1, i = 0;
	if (pos == 1) {
		x = head->data;
		p = head;
		head = head->next;
		free (p);
	}
	else {
		p = head;
		q = NULL;
		for (i = 0; i < pos - 1 && p; i++) {
			q = p;
			p = p->next;
		}
		if (p) {
			q->next = p->next;
			x = p->data;
			free(p);
		}
	}

	return x;
}

bool isSorted(struct Node* p) {
	int x = INT32_MIN;
	p = head;
	while (p != NULL) {
		if (p->data < x) {
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;
}

void deleteDup() {
	struct Node* p = head;
	struct Node* q = head->next;
	while (q != NULL) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}


void reverseByLink() {
	struct Node* p, * q, * r;
	q = r = NULL;
	p = head;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}

	head = q;
}

void reverseByData() {
	struct Node* p;
	int aux[10] = { 0 };
	int i = 0;
	p = head;
	while (p != NULL) {
		aux[i++] = p->data;
		p = p->next;
	}
	i--; p = head;
	while (p != NULL) {
		p->data = aux[i--];
		p = p->next;
	}
}

void reverseByRecursion(struct Node*q, struct Node*p) {
	if (p) {
		reverseByRecursion(p, p->next);
		p->next = q;
	}
	else {
		head = q;
	}
}




int main() {
	/*
	int A[] = { 3,5,7,10,15 };
	create(A, 5);
	display(head);
	printf("\n%d", Rcount(head));
	printf("\n%d", Rsum(head));
	printf("\n%d", Rmax(head));
	struct Node* f;
	f = search(head, 15);
	printf("\n%d ", f->data);
	printf("\n");
	Insert(5, 20);
	display(head);
	*/
	struct Node* q = NULL;
	int A[] = { 10, 10, 30, 40, 50 };
	create(A, 5);
	//SortedInsert(head, 15);
	//deleteDup();
	reverseByRecursion(q, head);
	display(head);
	
	

	return 0;
}