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
	printf("These numbers are used to initialize the Order Table.\n");
	printf("\033[33m[Warning] Max lenght is 1024.\033[37m\n");
	printf("Please Enter numbers(0 is end): ");
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
	printf("\n");
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
	for (;;) {
		int select;
		printf("-------------------------------\n");
		printf("1. Print Sequen List\n");
		printf("2. Insert a Number\n");
		printf("3. Reverse Sequen List\n");
		printf("4. Reinitializes Order Table\n");
		printf("5. Exit\n");
		printf("-------------------------------\n");
		printf("Enter 1 to 5:");
		scanf("%d", &select);
		switch (select) {
			case 1:
				print_SqList(pointer);
				break;
			case 2:
				printf("Enter location:");
				int location;
				scanf("%d", &location);
				printf("Enter Number:");
				int num;
				scanf("%d", &num);
				int status = insert_SqList(pointer, location, num);
				printf("Status Code : %d\n", status);
				print_SqList(pointer);
				printf("\n");
				break;
			case 3:
				reverse_SqList(pointer);
				printf("\n");
				break;
			case 4:
				pointer = initial_SqList();
				break;
			case 5:
				printf("The program has exited normally.(Status Code : 0)\n");
				exit(0);
			default:
				printf("\033[31m[Error] at selection number!\033[37m\n");
		}
	}
	return 0;
}
