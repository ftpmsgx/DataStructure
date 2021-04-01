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
	node *headNode = (node *)malloc(sizeof(node));
	headNode -> next = head;
        return headNode;
}

void singleList_Length(node *NewPointer) {
	int len = 0;
	node *temp = NewPointer -> next;
	while (temp) {
		len ++;
		temp = temp -> next;
	}
	node *pointer = NewPointer;
	node *NewNode = (node *)malloc(sizeof(node));
	NewNode -> data = len;
	NewNode -> next = pointer -> next;
        pointer -> next = NewNode;
}

void singleList_Delete(node *NewPointer, int number) {
	singleList first = NewPointer;
	singleList second = NewPointer -> next;
	while (second != NULL) {
		if (second -> data == number) {
			first -> next = second -> next;
			free(second);
			second = first -> next;
		} else {
			first = second;
			second = second -> next;
		}
	}
}

void print_SingleList(node *head) {
        node *pointer = head -> next;
        while (pointer) {
                printf("%d\t", pointer -> data);
                pointer = pointer -> next;
        }
        printf("\n");
}

void main() {
	singleList pointer = create_SingleList_Insert_End();
	print_SingleList(pointer);
	singleList_Length(pointer);
	print_SingleList(pointer);
	singleList_Delete(pointer, 3);
	print_SingleList(pointer);
}
