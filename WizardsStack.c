#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode_t {
    char data[20];
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char* value);
void stack_pop(Stack *stack);
char* stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char* value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->data,value);
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

char* stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main() {
		int n;
		char cmd[20], name[20];
		Stack path;
		stack_init(&path);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (cmd[0] == 'H') { // Sleep
			scanf("%s", name);
			stack_push(&path,name);
		} else if (cmd[0] == 'B') {	// Kick
			if (!stack_isEmpty(&path))
				stack_pop(&path);
		} 
        else {
			if (stack_isEmpty(&path))
				puts("Hey you, you're finally awake");
			else
				printf("%s\n", stack_top(&path));
		}
	}
	return 0;
}
