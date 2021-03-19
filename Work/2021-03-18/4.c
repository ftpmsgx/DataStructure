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

int Delete_SequenList(SequenList *L, int i) {
	if (L -> last == -1) {
		printf("\033[31m[Error] This table is full!\n\033[37m");
		return -1;
	}
	if (i >= L -> last || i < 0) {
		printf("\033[31m[Error] Position out of range.\n\033[37m");
		return -1;
	}
	int j;
	for (j = i; j <= L -> last; j++) {
		L -> data[j] = L -> data[j + 1];
	}
	L -> last --;
	L -> data[j] = 0;
	printf("\033[32mDelete was successfully!\n\033[37m");
	return 0;
}

void main() {
	SequenList *pointer = initial_SequenList();
	print_SequenList(pointer);
	int location = 3;
	int status = Delete_SequenList(pointer, location - 1);
	print_SequenList(pointer);
	printf("Status Code : %d\n", status);
	return 0;
}
