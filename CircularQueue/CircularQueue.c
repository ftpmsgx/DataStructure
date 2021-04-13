#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct CircularQueue {
	int data[MAX];
	int front;	// Queue head
	int rear;	// Queue end
}CircularQueue;

CircularQueue *init_CircularQueue() {
	CircularQueue *pointer = (CircularQueue *)malloc(sizeof(CircularQueue));
	if (pointer != NULL) {
		pointer -> front = 0;
		pointer -> rear = 0;
	}
	return pointer;
}

int full_CircularQueue(CircularQueue *pointer) {
	if ((pointer -> rear + 1) % MAX == pointer -> front) {
		return 1;
	}
	return 0;
}

int enter_CircularQueue(CircularQueue *pointer, int number) {
	if (full_CircularQueue(pointer)) {
		return 0;
	}
	pointer -> data[pointer -> rear] = number;
	pointer -> rear = (pointer -> rear + 1) % MAX;
	return 1;
}

int delete_CircularQueue(CircularQueue *pointer, int *p) {
	if (pointer -> front == pointer -> rear) {
		return 0;
	}
	*p = pointer -> data[pointer -> front];
	pointer -> front = (pointer -> front + 1) % MAX;
	return 1;
}

void main() {
	CircularQueue *pointer = init_CircularQueue();
	for (int i = 1; i <= 5; ++i) {
		enter_CircularQueue(pointer, i);
	}
	int x;
	while (pointer -> front != pointer -> rear) {
		delete_CircularQueue(pointer, &x);
		printf("%5d", x);
	}
	putchar('\n');
}

