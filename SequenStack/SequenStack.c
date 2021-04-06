#include <stdio.h>
#include <stdlib.h>

#define boolean int
#define true 1
#define false 0

#define MAXSIZE 1024

typedef struct Stack {
	int data[MAXSIZE];
	int top;
}SequenStack;

SequenStack *init_Stack() {
	SequenStack *s = (SequenStack *)malloc(sizeof(SequenStack));
	if (s != NULL) {
		s -> top = -1;
	}
	return s;
}

boolean push(SequenStack *s, int number) {
	if (s -> top >= MAXSIZE - 1) {
		return false;
	} else {
		s -> top++;
		s -> data[s -> top] = number;
		return true;
	}
}

boolean pop(SequenStack *s, int *t) {
	if (s -> top == -1) {
		return false;
	} else {
		*t = s -> data[s -> top];
		s -> top--;
		return true;
	}
}

void main() {
	SequenStack *s = init_Stack();
	for (int i = 0; i <= 4; i++) {
		push(s, i);
	}
	int e;
	while (s -> top != -1) {
		pop(s, &e);
		printf("%5d\t", e);
	}
	printf("\n");
}
