#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
	int data[MAX];
	int end;
} SqList;

SqList *initial_SqList() {
	SqList *pointer;
	int i = 0;
	int num;
	pointer = (SqList *)malloc(sizeof(SqList));
	if (pointer != NULL) {
		pointer -> end = -1;
	}
	printf("Please Enter a number: ");
	scanf("%d", &num);
	while (num) {
		pointer -> data[i++] = num;
		pointer -> end++;
		scanf("%d", &num);
	}
	return pointer;
}

void print_SqList(SqList *pointer) {
	for (int i = 0; i <= pointer -> end; i++) {
		printf("%5d", pointer -> data[i]);
	}
}

int insert_SqList(SqList *pointer, int location, int number) {
	if (pointer -> end >= MAX - 1) {
		printf("This SqList is full!\n");
		return -1;
	}
	if (location >= pointer -> end + 2) {
		printf("Position out of range.\n");
		return 1;
	}
	for (int j = pointer -> end; j >= location; j--) {
		pointer -> data[j + 1] = pointer -> data[j];
	}
	pointer -> data[location] = number;
	pointer -> end++;
	return 0;
}

void reverse_SqList(SqList *pointer) {
	if (pointer -> end == -1) {
		printf("This table is empty!\n");
		return;
	}
	int temp;
	for (int i = 0, j = pointer -> end; i < j; i++, j--) {
		temp = pointer -> data[i];
		pointer -> data[i] = pointer -> data[j];
		pointer -> data[j] = temp;
	}
}

int main() {
	SqList *pointer = initial_SqList();
	reverse_SqList(pointer);
	print_SqList(pointer);
	printf("\n");
	// int status = insert_SqList(pointer, 2, 60);
	// printf("Status Code : %d\n", status);
	// print_SqList(pointer);
	// printf("\n");
	return 0;
}
