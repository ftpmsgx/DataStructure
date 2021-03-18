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
	if (pointer == NULL) {
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

int Search_SequenList(SequenList *L, int key) {
	if (L -> last == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return -1;
	}
	int flag = 0;
	int i, j;
	for (i = 0, j = L -> last; i <= j; i++, j--) {
		if (L -> data[i] == key) {
			flag = 1;
			return i;
		}
		if (L -> data[j] == key) {
			flag = 1;
			return j;
		}
	}
	if (!flag) {
		printf("\033[31m[404]Not found this number!\n\033[37m");
		return 0;
	}
}

void main() {
	SequenList *pointer = initial_SequenList();
	printf("The logic location of this number: %d\n", Search_SequenList(pointer, 576));
	printf("The logic location of this number: %d\n", Search_SequenList(pointer, 900));
	return 0;
}
