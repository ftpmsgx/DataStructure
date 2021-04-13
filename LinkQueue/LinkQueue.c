#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct LinkQueue {
	int data;
	struct LinkQueue *next;
}LinkQueueNode;

typedef struct LinkQueue_Pointer {
	LinkQueueNode *front, *rear;
}LinkQueue_Pointer;

LinkQueue_Pointer *init_LinkQueue() {
	LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	node -> next = NULL;
	LinkQueue_Pointer *pointer = (LinkQueue_Pointer *)malloc(sizeof(LinkQueue_Pointer));
	pointer -> front = node;
	pointer -> rear = node;
	return pointer;
}

int enter_LinkQueue(LinkQueue_Pointer *pointer, int number) {
	LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (node == NULL) {
		return 0;
	}
	node -> data = number;
	node -> next = NULL;
	pointer -> rear -> next = node;
	pointer -> rear = node;
	return 1;
}

int delete_LinkQueue(LinkQueue_Pointer *pointer, int *x) {
	LinkQueueNode *node;
	if (pointer -> front == pointer -> rear) {
		return 0;
	}
	node = pointer -> front -> next;
	*x = node -> data;
	pointer -> front -> next = node -> next;
	if (node == pointer -> rear) {
		pointer -> rear = pointer -> front;
	}
	free(node);
	return 1;
}

void main() {
	LinkQueue_Pointer *pointer = init_LinkQueue();
	int x;
	for (int i = 1; i <= 5; i++) {
		enter_LinkQueue(pointer, i);
	}
	while (pointer -> front != pointer -> rear) {
		delete_LinkQueue(pointer, &x);
		printf("%5d", x);
	}
	putchar('\n');
}
