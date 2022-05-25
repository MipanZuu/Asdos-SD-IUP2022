#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Node{
	int data;
	struct Node *Link;
	int max;
	int min;
} Node;

typedef struct List{
	unsigned size;
	Node *head;
} Stack;


void init(Stack *list);
bool isEmpty(Stack *list);
void push(Stack*list, int value);
void pop(Stack *list);
int top(Stack *list);
unsigned size(Stack *list);


void init(Stack *list){
	list->size = 0;
	list->head = NULL;
}

bool isEmpty(Stack *list){
	return(list->head == NULL);
}

void push(Stack *list, int value){
	
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode){
		if(isEmpty(list)){
			newNode->Link = NULL;
			newNode->max = value;
			newNode->min = value;
		}
		else{
			newNode->Link = list->head;
			if(value > list->head->max) newNode->max = value; 
			else newNode->max = list->head->max;
			
			if(value < list->head->min)newNode->min = value;
			else newNode->min = list->head->min;
		}
		newNode->data = value;
		list-> head = newNode;
	}
	
}
	


void pop (Stack *list){
	if(!isEmpty(list)){
		Node *temp = list->head;
		list->head = list->head->Link;
		free(temp);
		list->size--;
	}
}

int top(Stack* list){
	
	if(!isEmpty(list)) 
	return list->head->data;
	return 0;
}

unsigned size(Stack *list){
	return list->size;
}



int main(){
	Stack myStack;
	init(&myStack);
	int rounds,i;
	scanf("%d", &rounds);
	
	
	for(i = 0; i < rounds; i++){
		char input[10000];
		getchar();
		scanf("%s", &input);
		Node *temp2 = myStack.head;
		
		if(strcmp(input,"push") == 0){
			
			int value;
			scanf("%d", &value);
			
			push(&myStack, value);
			
			
		}
	    else if(strcmp(input,"top")==0){
			
			int valueOfTop = top (&myStack);
			printf("%d\n", valueOfTop);
		}
		else if(strcmp(input,"pop")==0){
			
			pop(&myStack);
		}
		else if(strcmp(input,"max")==0){
			int max = temp2->max;
			printf("%d\n", myStack.head->max);
			
		    
		}else if(strcmp(input,"min") == 0){
			int min = temp2->min;
			printf("%d\n", min);
			
		}
	}


	return 0;

}
