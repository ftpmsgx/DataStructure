#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

#define ERROR -1
#define OK 1

#define boolean int
#define false 0
#define true 1

typedef int ElemType;

typedef struct node {
	// Data domain
	ElemType data;
	// Points to the next succeeding element
	struct node *next;
}node, *singleList;

/**
 * Create a SingleList.
 * Insert data at head.
 * This List head is not empty.
 */
singleList create_SingleList_Insert_Head() {
	singleList head = NULL;
	node *NewNode;
	int flag;
	printf("Please Enter numbers(0 is end):");
	scanf("%d", &flag);
	while (flag) {
		NewNode = (node *)malloc(sizeof(node));
		NewNode -> data = flag;
		NewNode -> next = head;
		head = NewNode;
		scanf("%d", &flag);
	}
	return head;
}

/**
 * Create a SingleList.
 * Insert data at end.
 * This List head is empty.(Maybe)
 * :)
 */
singleList create_SingleList_Insert_End() {
	singleList head = NULL;
	singleList end = NULL;
	node *NewNode;
	int flag;
	printf("Please Enter numbers(0 is end):");
	scanf("%d", &flag);
	while (flag) {
		NewNode = (node *)malloc(sizeof(node));
		NewNode -> data = flag;
		if (head == NULL) {
			head = NewNode;
		} else {
			end -> next = NewNode;
		}
		end = NewNode;
		scanf("%d", &flag);
	}
	if (end != NULL) {
		end -> next = NULL;
	}
	return head;
}

/**
 * Print this new SingleList.
 */
void print_SingleList(node *head) {
	node *pointer = head;
	while (pointer) {
		printf("%d\t", pointer -> data);
		pointer = pointer -> next;
	}
	printf("\n");
}

/**
 * Search nth node.
 */
node *get_SingleList(singleList NewNode, int number) {
	node *pointer = NewNode;
	int count = 0;
	while (pointer != NULL && count < number) {
		pointer = pointer -> next;
		count++;
	}
	return count == number? pointer: NULL;
}

/**
 * Insert a data after locate.
 */
boolean insert_SingleList(singleList NewPointer, int locate, int number) {
	node *pointer;
	node *NewNode;
	pointer = get_SingleList(NewPointer, locate - 1);
	if (pointer == NULL) {
		printf("\033[31m[Error] Position out of range.\n\033[37m");
		return false;
	} else {
		// Apply for dynamic space
		NewNode = (node *)malloc(sizeof(node));
		// Insert number to data
		NewNode -> data = number;
		// Point the pointer of newnode to the pointer of pointer
		//
		//Sketch Map:
		//
		// NewNode0 ---> NewNode ---> NewNode1
		//				^
		//				|
		//				pointer
		//
		//|||||||||||||||||||||||||||||||||||||||
		//|||||||||||||||||||||||||||||||||||||||
                // NewNode0 ---> NewNode      NewNode1
		// 		    |             ^
                //                  |             |
                //                  |             |
                //                  ------->   pointer
		NewNode -> next = pointer -> next;
		// Point pointer to NewNode
		pointer -> next = NewNode;
		return true;
	}
}

/**
 * Delete a data after locate.
 */
boolean delete_SingleList(singleList pointer, int locate) {
	singleList before;
	singleList NewPointer;
	before = get_SingleList(pointer, --locate);
	if (before == NULL) {
		printf("\033[31m[Error] Node %d is NULL\n\033[37m", locate);
		return false;
	} else if (before -> next == NULL) {
		printf("\033[31m[Error] Node %d is NULL\n\033[37m", locate + 1);
                return false;
	} else {
		NewPointer = before -> next;
		before -> next = NewPointer -> next;
		free(NewPointer);
		return true;
	}
}

void main() {
	singleList test_first = create_SingleList_Insert_Head();
	print_SingleList(test_first);
	singleList test_second = create_SingleList_Insert_End();
	print_SingleList(test_second);
	if (insert_SingleList(test_second, 3, 60)) {
		print_SingleList(test_second);
	}
	if (delete_SingleList(test_second, 3)) {
		print_SingleList(test_second);
	}
}
