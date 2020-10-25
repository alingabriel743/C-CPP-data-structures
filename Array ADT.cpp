#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

class Array {
private:
	int* A;
	int size;
	int length;
	//void swap(int* x, int* y);

public:
	Array() {
		size = 10;
		length = 0;
		A = new int[size];
	}
	Array(int sz) {
		size = sz;
		length = 0;
		A = new int[size];
	}
	~Array() {
		delete A;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);
	int LinearSearch( int x);
	int BinarySearch(int x);
	int get(int index);
	void set(int index, int elem);
	int max();
	int min();
	int sum();
	float Avg();
	void reverse();
	void insertSort(int x);
	int RecBinarySearch(int l, int h, int key);
	int isSorted();
	Array* merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* difference(Array arr2);

};



void Array::Display() {
	int  i;
	printf("Elements are: \n");
	for (i = 0; i < length; i++)
		printf("%d ", A[i]);
}

void Array::Append(int x) {
	if (length < size) {
		A[length++] = x;
	}
}

void Array::Insert(int index, int x) {
	int i = 0;
	if (index >= 0 && index < length) {
		for (i = length; i > index; i--) {
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}

int Array::Delete(int index) {
	if (index >= 0 && index < length) {
		int x = A[index];
		for (int i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
		return x;
	}

	return 0;
}

int Array::LinearSearch(int x) {
	int i;
	for (i = 0; i < length; i++) {
		if (x == A[i]) {
			swap(&A[i], &A[0]);
			return i;
		}

	}
	return -1;
}

int Array::get(int index) {
	if (index >= 0 && index < length)
		return A[index];
}

void Array::set(int index, int elem) {
	if (index >= 0 && index < length) {
		A[index] = elem;
	}
}
int Array::max() {
	int max = A[0];
	for (int i = 1; i < length; i++) {
		if (A[i] > max)
			max = A[i];
	}

	return max;
}
int Array::min() {
	int min = A[0];
	for (int i = 1; i < length; i++) {
		if (A[i] < min)
			min = A[i];
	}

	return min;
}

int Array::sum() {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += A[i];
	return sum;
}

float Array::Avg() {
	return sum() / (float)length;
}

void Array::reverse() {
	int i = 0;
	int j = length - 1;
	for (i = 0, j = length - 1; i < j; i++) {
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

void Array::insertSort(int x) {
	int i = length - 1;
	while (A[i] > x) {
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
}

int Array::isSorted() {
	for (int i = 0; i < length - 1; i++) {
		if (A[i] > A[i + 1]) {
			return 0;
		}
	}
	return 1;
}


int Array::BinarySearch(int x) {
	int l, h, mid;
	l = 0;
	h = length - 1;
	while (l <= h) {
		mid = (l + h) / 2;
		if (x == A[mid])
			return mid;
		else if (x < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}

int Array::RecBinarySearch(int l, int h, int key) {
	int mid = 0;
	while (l <= h) {
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			return RecBinarySearch(l, mid - 1, key);
		else return RecBinarySearch(mid + 1, h, key);
	}

	return -1;
}

Array* merge(Array arr2) {
	int i, j, k;
	i = j = k = 0;
	Array *arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j]) {
			arr3->A[k++] = A[i++];
		}
		else {
			arr3->A[k++] = arr2.A[j++];
		}
	}
	for (; i < length; i++) {
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++) {
		arr3->A[k++] = arr2.A[j];
	}

	length = k;
	

	return arr3;
}

Array* Union(Array arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else {
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* difference(struct Array* arr1, struct Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++;

			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}


int main()
{
	Array *arr1;
	int ch;
	int x, index;
	printf("Enter Size of Array");
	scanf("%d", &arr1.size);
	arr1.A = (int*)malloc(arr1.size * sizeof(int));
	arr1.length = 0;

	do
	{
		printf("\n\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6.Exit\n");
		printf("enter you choice ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: printf("Enter an element and index");
			scanf("%d%d", &x, &index);
			Insert(&arr1, index, x);
			break;
		case 2: printf("Enter index ");
			scanf("%d", &index);
			x = Delete(&arr1, index);
			printf("Deleted Element is %d\n", x);
			break;
		case 3:printf("Enter element to search ");
			scanf("%d", &x);
			index = LinearSearch(&arr1, x);
			printf("Element index %d", index);
			break;
		case 4:printf("Sum is %d\n", sum(arr1));
			break;
		case 5:Display(arr1);
		}
	} while (ch < 6);
	return 0;
}