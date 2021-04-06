#include <stdio.h>
#include <stdlib.h>

#define boolean int
#define true 1
#define false 0

typedef struct LinkStackNode {
	int data;
	struct LinkStackNode *next;
}LinkStack;

LinkStack *init_LinkStack() {
	LinkStack *top = (LinkStack *)malloc(sizeof(LinkStack));
	top -> next = NULL;
	return top;
}

boolean push(LinkStack *top, int number) {
	LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
	if (!p) {
		return false;
	}
	p -> data = number;
	// printf("%5d\t", p -> data);
	p -> next = top -> next;
	top -> next = p;
	return true;
}

boolean pop(LinkStack *top, int *t) {
	LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
	if (top == NULL) {
		return false;
	}
	p = top -> next;
	*t = top -> next -> data;
	top -> next = p -> next;
	free(p);
	return true;
}

void main() {
	LinkStack *p = init_LinkStack();
	int number;
	scanf("%d", &number);
	while (number) {
		push(p, number % 2);
		// printf("%5d\t%5d\n", p -> data, number % 2);
		number /= 2;
	}
	int e;
	while (p -> next != NULL) {
		pop(p, &e);
		printf("%5d\t", e);
	}
	printf("\n");
}
