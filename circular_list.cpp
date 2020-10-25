#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void Create(int A[], int n) {
	struct Node* t, *last;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = A[0];
	head->next = head;
	last = head;
	for (int i = 1; i < n; i++) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;	
	}
}

void Insert(struct Node* p, int index, int x){
	struct Node* t;
	int i;
	if (index == 0){
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		if (head == NULL){

			head = t;
			head->next = head;
		}
		else{
			while (p->next != head)p = p->next;
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else{
		for (i = 0; i < index - 1; i++)p = p->next;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

void rDisplay(struct Node* p) {
	static int flag = 0;
	if (p != head || flag == 0) {
		flag = 1;
		printf("%d ", p->data);
		rDisplay(p->next);
	}

	flag = 0;
}

void Display(struct Node* h)
{
	do
	{
		printf("%d ", h->data);
		h = h->next;
	} while (h != head);

}


int Delete(int index) {
	struct Node* t, *q = (struct Node*)malloc(sizeof(struct Node));
	int value = 0;
	if (index == 1) {
		q = head;
		while (q->next != head) {
			q = q->next;
		}
		value = head->data;
		q->next = head->next;
		free(head);
		head = q->next;
	}
	else {
		q = head;
		for (int i = 0; i < index - 2; i++) {
			q = q->next;
		}
		t = q->next;
		value = t->data;
		q->next = t->next;
		free(t);
	}

	return value;
}

int main()
{
	int A[] = { 2,3,4,5,6 };
	Create(A, 5);
	//Insert(head, 0, 10);
	Delete(5);
	Display(head);
	return 0;
}