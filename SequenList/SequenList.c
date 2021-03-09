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
	printf("Order table: \n");
	for (int i = 0; i <= pointer -> end; i++) {
		printf("%5d", pointer -> data[i]);
	}
	printf("\n");
}

int insert_SqList(SqList *pointer, int location, int number) {
	if (pointer -> end >= MAX - 1) {
		printf("\033[31m[Error] This table is full!\n\033[37m");
		return -1;
	}
	if (location >= pointer -> end + 2) {
		printf("\033[31m[Error] Position out of range.\n\033[37m");
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
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return;
	}
	int temp;
	for (int i = 0, j = pointer -> end; i < j; i++, j--) {
		temp = pointer -> data[i];
		pointer -> data[i] = pointer -> data[j];
		pointer -> data[j] = temp;
	}
	print_SqList(pointer);
}

int query_SqList(SqList *pointer, int number) {
	if (pointer -> end == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return -1;
	}
	int flag = 0;
	int i, j;
	for (i = 0; i <= pointer -> end; i++) {
		if (pointer -> data[i] == number) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("The physics location of this number: %d\n", i);
		printf("The logic location of this number: %d\n", i + 1);
		return i;
	} else {
		printf("\033[31m[404]Not found this number!\n\033[37m");
		return -2;
	}
}

void delete_SqList(SqList *pointer) {
	printf("Please Enter a number that you want to delete: ");
	if (pointer -> end == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return;
	}
	int number;
	scanf("%d", &number);
	int flag = query_SqList(pointer, number);
	if (flag >= 0) {
		int i;
		for (i = flag; i < pointer -> end; i++) {
			pointer -> data[i] = pointer -> data[i + 1];
		}
		pointer -> data[i] = 0;
		pointer -> end--;
		printf("\033[32mDelete was successfully!\n\033[37m");
		print_SqList(pointer);
	} else if (flag == -1) {
		printf("\033[31m[Error] Delete failed!\n");
		printf("\033[31m[Error] This number was not found!\n\033[37m");
	} else {
		printf("\033[31m[Error] Delete failed!\n");
		printf("\033[31m[Error] This table is empty!\n\033[37m");
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
		printf("5. Query a Number\n");
		printf("6. Delete a Number\n");
		printf("7. Exit\n");
		printf("-------------------------------\n");
		printf("Enter 1 to 7:");
		scanf("%d", &select);
		switch (select) {
			case 1:
				print_SqList(pointer);
				break;
			case 2:
				printf("Enter location(Logic position):");
				int location;
				scanf("%d", &location);
				printf("Enter Number:");
				int num;
				scanf("%d", &num);
				int status = insert_SqList(pointer, location - 1, num);
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
				printf("Please Enter a number that you want to Query: ");
				int query_Num;
				scanf("%d", &query_Num);
				int clearStatusCode = query_SqList(pointer, query_Num);
				break;
			case 6:
				delete_SqList(pointer);
				break;
			case 7:
				printf("The program has exited normally.(Status Code : 0)\n");
				exit(0);
			default:
				printf("\033[31m[Error] at selection number!\033[37m\n");
		}
	}
	return 0;
}
