#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

typedef int elemtype;

typedef struct {
	elemtype data[MAXSIZE];
	int last;
}SequenList;

SequenList *initial_SequenList() {
	SequenList *pointer;
	int i = 0;
	int number;
	pointer = (SequenList *)malloc(sizeof(SequenList));
	if (pointer != NULL) {
		pointer -> last = -1;
	}
	printf("These numbers are used to initialize the Order Table.\n");
	printf("\033[33m[Warning] Max lenght is 1024.\033[37m\n");
	printf("Please Enter numbers(0 is end): ");
	scanf("%d", &number);
	while (number) {
		pointer -> data[i++] = number;
		pointer -> last ++;
		scanf("%d", &number);
	}
	return pointer;
}

void print_SequenList(SequenList *pointer) {
	printf("Sequen List: \n");
	for (int i = 0; i <= pointer -> last; i++) {
		printf("%5d", pointer -> data[i]);
		if (!((i + 1) % 5)) {
			printf("\n");
		}
	}
	printf("\n");
}

void main() {
	SequenList *pointer = initial_SequenList();
	print_SequenList(pointer);
	return 0;
}
